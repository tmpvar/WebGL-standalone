var currentTest = '';

var testList = readfile('test/khronos-tests/conformance/00_test_list.txt');
var testFiles = testList.split('\n');
var currentFile = 0;

var sax = require('test/util/sax.js');
var webgl_tests = [];
function next_test(filename) {
  var text = readfile('test/khronos-tests/conformance/' + filename);
  var parser = sax.parser();
  parser.onerror = function (e) {
    console.log('PARSE ERROR', filename, e);
  };

  var text = text.replace(/([a-z_]*) (<)/ig,'$1 &lt;');

  var scriptText = "";
  var collectText = false;
  var testBody = "";

  parser.ontext = function (t) {
    if (collectText) {
      collectText(t);
    }
  };

  parser.onopentag = function (node) {
    collectText = false;
    testBody = "";
    if (node.name === "SCRIPT") {
      // TODO: shaders

      // collect the main test body
      if (!node.attributes.src) {
        collectText = function(text) {
          testBody += text;
        };
      }
    }
  };

  parser.onclosetag = function() {
    collectText = false;
  }

  parser.onend = function () {
    var test = {
      file : filename
    };
    function description(val) {
      test.name = val;
    }
    function testPassed() {
      test.pass = true;
    }
    function newCanvas() {
      return {
        getContext : function() {},
        toDataURL : function() {},
        addEventListener : function() {}
      };
    };
    var document = {
      getElementById : function() {
        return newCanvas();
      },
      createElement : function() {
        return newCanvas();
      }
    };
    var window = {
      document : document
    };
    var debug = function(){};
    var create3DContext = function() {
      return WebGLTestUtils.create3DContext();
    };
    var testFailed = function(msg) {
      test.fail = msg;
    };
    var shouldBe = function(should, be, msg) {
      if (should !== be) {
        testFailed(msg);
      }
    };
    var assertMsg = shouldBe;

    var glErrorShouldBe = shouldBe;


    var WebGLTestUtils = {
      create3DContext : function() {
        var ret = {};
        var not_implemented = function() {};

        var methods = [
          "activeTexture","attachShader","bindAttribLocation","bindBuffer","bindFramebuffer",
          "bindRenderbuffer","bindTexture","blendColor","blendEquation","blendEquationSeparate","blendFunc",
          "blendFuncSeparate","bufferData","bufferSubData","checkFramebufferStatus","clear","clearColor",
          "clearDepth","clearStencil","colorMask","compileShader","copyTexImage2D","copyTexSubImage2D",
          "createBuffer","createFramebuffer","createProgram","createRenderbuffer","createShader",
          "createTexture","cullFace","deleteBuffer","deleteFramebuffer","deleteProgram","deleteRenderbuffer",
          "deleteShader","deleteTexture","depthFunc","depthMask","depthRange","detachShader","disable",
          "disableVertexAttribArray","drawArrays","drawElements","enable","enableVertexAttribArray","finish",
          "flush","framebufferRenderbuffer","framebufferTexture2D","frontFace","generateMipmap",
          "getActiveAttrib","getActiveUniform","getAttachedShaders","getAttribLocation","getBufferParameter",
          "getContextAttributes","getExtension","getFramebufferAttachmentParameter","getParameter",
          "getProgramParameter","getProgramInfoLog","getRenderbufferParameter","getShaderParameter",
          "getShaderInfoLog","getShaderSource","getSupportedExtensions","getTexParameter","getUniform",
          "getUniformLocation","getVertexAttrib","getVertexAttribOffset","hint","isBuffer","isContextLost",
          "isEnabled","isFramebuffer","isProgram","isRenderbuffer","isShader","isTexture","lineWidth",
          "linkProgram","pixelStorei","polygonOffset","readPixels","releaseShaderCompiler","renderbufferStorage",
          "sampleCoverage","scissor","shaderSource","stencilFunc","stencilFuncSeparate","stencilMask",
          "stencilMaskSeparate","stencilOp","stencilOpSeparate","texParameterf","texParameteri","texImage2D",
          "texSubImage2D","uniform1f","uniform1fv","uniform1i","uniform1iv","uniform2f","uniform2fv","uniform2i",
          "uniform2iv","uniform3f","uniform3fv","uniform3i","uniform3iv","uniform4f","uniform4fv","uniform4i",
          "uniform4iv","uniformMatrix2fv","uniformMatrix3fv","uniformMatrix4fv","useProgram","validateProgram",
          "vertexAttrib1f","vertexAttrib1fv","vertexAttrib2f","vertexAttrib2fv","vertexAttrib3f",
          "vertexAttrib3fv","vertexAttrib4f","vertexAttrib4fv","vertexAttribPointer","viewport"
        ];

        methods.forEach(function(method) {
          ret[method] = not_implemented;
        });
        ret.getError = function() {
          return 0;
        };
        return ret;
      },
      setupTexturedQuad : function() {},
      fillTexture : function() {},
      drawQuad : function() {},
      checkCanvas : function() {},
    };

    webgl_tests.push(test);

    testBody = testBody.replace(/&lt;/g,'<');
    // run the test
    try {
      eval(testBody);
    } catch (e) {
      console.log(filename, e.message);
      test.error = e;
      test.file = filename;
    }


    run_next_test();
  };

  parser.write(text).close();
}

next_test(testFiles[currentFile]);

function run_next_test() {
  currentFile++;
  while (!testFiles[currentFile] || testFiles[currentFile].indexOf('#') !== -1 || testFiles[currentFile].indexOf('.txt') !== -1) {
    currentFile++;
  }

  if (testFiles[currentFile] && currentFile < testFiles.length) {
    next_test(testFiles[currentFile]);
  } else {
    final();
  }
}

function final() {
  webgl_tests.forEach(function(test) {
    if (!test.pass) {
      if (!test.error) {
        console.log('✖ -', test.name || test.file, test.fail);
      } else {
        var stackParts = test.error.stack.split('\n');
        stackParts.length = 5;
        test.error.stack = stackParts.join('\n    ')

        console.log('✖ -', test.name || test.file, '-', test.error.message);
        console.log('\n    ' + test.error.stack + '\n');
      }
    } else {
      console.log('√ - ' + test.name);
    }
  });
  console.log('total webgl_tests', testFiles.length, 'ran', webgl_tests.length);

}
