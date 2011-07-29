var fs = require('fs');
var idl = fs.readFileSync(__dirname + '/webgl.idl').toString();

var t_h = fs.readFileSync(__dirname + '/templates/file.h').toString();
var t_cc = fs.readFileSync(__dirname + '/templates/file.cc').toString();

var currentProperties = [];
var current = '';
var h = '';
var cc = '';
var queue = '';
var files = {};
var includes = [];


var skip = [
  'void', 'void*', 'bool', 'int', 'float', 'long',
  'double', 'long', 'GLfloat', 'GLenum', 'GLboolean', 'GLint',
  'GLsizeiptr', 'GLclampf', 'GLsizei', 'GLuint', 'GLbitfield',
  'GLintptr', 'GLclampf', 'GLboolean'
];

idl = idl.replace(/readonly attribute/g, 'readonly');
idl = idl.replace(/attribute boolean/g, 'bool');
idl = idl.replace(/ boolean/g, ' bool');
idl = idl.replace(/\[[ ]*\]/g, '\*\*');

idl = idl.replace(/sequence<(.*)>/g, '$1\*\*');

function addInclude(file, addLine) {
  file = file.replace(/\*/g, '');
  var include = '#include "' + file + '.h"';
  
  if (file && includes.indexOf(include) < 0 && skip.indexOf(file) === -1) {
    includes.push(include);
    if (addLine !== false && !files[file]) {
      lines.push('interface ' + file + ' {');
      lines.push(' ');
      lines.push('};');
      files[file] = true;
    }
  }
}

var lines = idl.split('\n');
var line;
var i = 0;
while(1) {
  i++;
  if (i >= lines.length) {
    break;
  }

  var line = lines[i];
  line = line.replace(/any/, 'void* ');
  line = line.replace(/object/, 'void* ');

  // Handle interfaces
  if (line.indexOf('interface') > -1) {
    var match = line.match(/interface +(.*) +\{/);
    var nameParts = match[1].split(' : ');
    var name, parent = '', parentClass = '', parentInclude = '';

    if (nameParts.length === 2) {
      parent = nameParts.pop();
      parentClass = ' : ' + parent;
      addInclude(parent);
    }

    name = current = nameParts.pop().replace(/^\W*|\W*$/g,'');
    files[name] = true;

    h = t_h.replace(/%FILE%/g, name);
    h = h.replace(/%PARENT_CLASS%/, parentClass);

    cc = t_cc.replace(/%FILE%/g, name);
    cc += name + '::'  + name + '() {\n  \n}\n\n';
    cc += name + '::~' + name + '() {\n  \n}\n\n';

    currentProperties = [
    ];

  // Handle the end of an interface
  } else if (line.indexOf('};') > -1) {
    if (current === '') {
      continue;
    }

    if (currentProperties.length > 0) {

      var h_props = [];
      currentProperties.forEach(function(prop) {
        // only function calls
        if (prop.indexOf('(') > -1) {
          h_props.push(prop);

          var propParts = prop.replace(/^ +/, '').split(' ');
          if (propParts.length > 2) {
            //propParts[2] = current + '::' + propParts[2];
            prop = propParts.join(' ').replace(';', ' {');
            // calculate extra includes
            var matches = prop.match(/^(.+) (.*)\((.*)\)/i);
            if (matches && matches.length === 4) {
              addInclude(matches[1]);
              
              var args = [];
              
              matches[3].split(', ').forEach(function(arg) {
  
                arg = arg.replace(/sequence<(.*)>/, '$1\*');
                arg = arg.replace(/^boolean$/, 'bool');

                args.push(arg);
                var type = arg.split(' ')[0];
                addInclude(type);
              });

              cc += matches[1] + ' ' + current + '::' + matches[2] + '(' + args.join(', ') + ') {\n  \n}\n\n';
            } else {
              console.log('miss', prop, matches);
            }
          }
          
          if (propParts.length === 2) {
            addInclude(propParts[0]);
            cc += propParts[0] + ' ' + current + '::' + propParts[1].replace(';', ' {\n  \n}\n\n') + '\n';
          }

        } else {
          
          // split off = and add instance to .cc
          var matches = prop.match(/(.*) (.*) = (.*)$/i);
          if (matches) {
            matches[1] = matches[1].replace('const', 'static const');
            h_props.push(matches[1] + ' ' + matches[2] + ' = ' + matches[3] + ';');
          } else {
            
            
            attributeMatch = prop.match(/readonly (.*) (.*);/);

            if (attributeMatch) {
              addInclude(attributeMatch[1]);
              var titleCase = attributeMatch[2].substring(0,1).toUpperCase() + attributeMatch[2].substring(1);
              prop = attributeMatch[1] + ' get' + titleCase + '();'
              cc += attributeMatch[1] + ' ' + current + '::get' + titleCase + '() {\n  \n}\n\n';
            }

            h_props.push('    ' + prop.replace(/^\W*/, ''));
          }
        }
      });

      h = h.replace(/%PUBLIC%/, '\n  public:\n' + h_props.join('\n') + '\n');
    }

    h = h.replace(/%PARENT_INCLUDE%/, includes.join('\n') + '\n');
    h = h.replace(/%PUBLIC%/, '\n  public:\n');
    includes = [];

    fs.writeFileSync(__dirname + '/../src/' + current + '.h', h);
    fs.writeFileSync(__dirname + '/../src/' + current + '.cc', cc);

    current = '';
    currentProperties = [];
    h = '';
    cc = '';
  } else if (line.indexOf(';') > -1) {
    
    queue += line;
    queue = queue.split('\n').join('');

    currentProperties.push('   ' + queue.replace(/ +/g,' '));
    queue = '';
  } else if (line.match(/(, )|,$/)) {
    queue += line;
  } else if (queue !== '') {
    queue += line.replace(/ +/g,' ');
  }
};