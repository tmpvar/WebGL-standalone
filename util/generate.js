var fs = require('fs');
var idl = fs.readFileSync('./webgl.idl').toString();

var t_h = fs.readFileSync('./templates/file.h').toString();
var t_cc = fs.readFileSync('./templates/file.cc').toString();

var currentProperties = [];
var current = '';
var h = '';
var cc = '';
var queue = '';
var files = {};
var includes = [];


var skip = ['void', 'void*', 'boolean', 'int', 'float', 'double', 'GLfloat', 'GLenum', 'GLboolean'];

var lines = idl.split('\n');
var line;
for (var i=0; i<lines.length; i++) {
  var line = lines[i];
  line = line.replace(/any/, 'void* ');

  // Handle interfaces
  if (line.indexOf('interface') > -1) {
    var match = line.match(/interface *(.*) *\{/);
    var nameParts = match[1].split(' : ');
    var name, parent = '', parentClass = '', parentInclude = '';

    if (nameParts.length === 2) {
      parent = nameParts.pop();
      parentClass = ' : ' + parent;
      includes.push('#include "' + parent + '.h"');
    }

    name = current = nameParts.pop();
    files[name] = true;

    h = t_h.replace(/%FILE%/g, name);
    h = h.replace(/%PARENT_CLASS%/, parentClass);

    cc = t_cc.replace(/%FILE%/g, name);
    cc += name + '::'  + name + '() {\n  \n}\n\n';
    cc += name + '::~' + name + '() {\n  \n}\n\n';

    currentProperties = [
      '    ' + name + '();',
      '    ~' + name + '();\n'
    ];

  // Handle the end of an interface
  } else if (line.indexOf('};') > -1) {
    if (current === '') {
      return;
    }

    if (currentProperties.length > 0) {
      h = h.replace(/%PUBLIC%/, '\n  public:\n' + currentProperties.join('\n') + '\n');
      
      currentProperties.forEach(function(prop) {
        // only function calls
        if (prop.indexOf('(') > -1) {
          var propParts = prop.replace(/^ */, '').split(' ');
          if (propParts.length > 2) {
            propParts[1] = current + '::' + propParts[1];
            prop = propParts.join(' ').replace(';', ' {');
            
            // calculate extra includes
            var matches = prop.match(/^(.*) .*\((.*)\)/);
            if (matches.length === 3) {
              if (skip.indexOf(matches[1]) === -1) {
                
                if (!files[matches[1]]) {
                  console.log('creating a new interface', matches[1])
                  lines.push('interface ' + matches[1] +' {');
                  lines.push('};');
                  files[matches[1]] = true;
                }
                
                includes.push('#include "' + matches[1] + '.h"');
              }
              
              
              
            }
            
            cc += prop + '\n  \n}\n\n';
          }
        }
      });
    }

    h = h.replace(/%PARENT_INCLUDE%/, includes.join('\n') + '\n');
    includes = [];
    console.log(cc)
    fs.writeFileSync('../src/' + current + '.h', h);
    fs.writeFileSync('../src/' + current + '.cc', cc);

    current = '';
    currentProperties = [];
    h = '';
    cc = '';
  } else if (line.indexOf(';') > -1) {
    queue += line;
    queue = queue.split('\n').join('');
    
    // Add includes if needed
    
    currentProperties.push('   ' + queue.replace(/ +/g,' '));
    queue = '';
  } else if (line.match(/(, )|,$/)) {
    queue += line;
  } else if (queue !== '') {
    queue += line.replace(/ +/g,' ');
  }
};