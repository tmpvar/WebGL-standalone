var currentTest = '';

var testList = readfile('test/khronos-tests/conformance/00_test_list.txt');
var testFiles = testList.split('\n');

// clean off trailing slash
testFiles.pop();

var currentFile = 0;
var webgl_test;


var assertMsg = shouldBe;

//var glErrorShouldBe = shouldBe;

var testIntro = readfile('test/khronos-tests/resources/js-test-pre.js');
eval(testIntro);

try {
  var testFunctions = readfile('test/khronos-tests/conformance/resources/webgl-test.js');
  eval(testFunctions);
  var testUtils = readfile('test/khronos-tests/conformance/resources/webgl-test-utils.js');
  eval(testUtils)
} catch (e) {
  console.log(e.stack);
}

var isTestPassing = function(test) {
  return (!test.pass || test.error || test.fail || test.skipped) ? false : true;
}

checkPixel = function() {};
var WebGLRenderingContext = require('lib/webgl.js');
create3DContext = function() {
  return new WebGLRenderingContext();
};

newCanvas = function() {
  var canvas = {
    getContext : function(mode) {
      if (mode === '2d') {
        var stubs = ["lineWidth", "textBaseline", "strokeStyle", "lineJoin", "canvas", "shadowBlur", "globalAlpha", "textAlign", "globalCompositeOperation", "font", "shadowColor", "miterLimit", "shadowOffsetY", "fillStyle", "shadowOffsetX", "lineCap", "save", "restore", "scale", "rotate", "translate", "transform", "setTransform", "createLinearGradient", "createRadialGradient", "clearRect", "fillRect", "beginPath", "closePath", "moveTo", "lineTo", "quadraticCurveTo", "bezierCurveTo", "arcTo", "rect", "arc", "fill", "stroke", "clip", "isPointInPath", "measureText", "setAlpha", "setCompositeOperation", "setLineWidth", "setLineCap", "setLineJoin", "setMiterLimit", "clearShadow", "fillText", "strokeText", "setStrokeColor", "setFillColor", "strokeRect", "drawImage", "drawImageFromRect", "setShadow", "createPattern", "putImageData", "createImageData", "getImageData"];
        var ret = {};
        stubs.forEach(function(stub) {
          ret[stub] = function() {
            return {
              data : {}
            }
          };
        })
        return ret;
      } else {
        return create3DContext();
      }
    },
    clientWidth : 0,
    clientHeight : 0,
    style : {
      set width(px) {
        canvas.clientWidth = parseInt(px, 10);
      },
      set height(px) {
        canvas.clientHeight = parseInt(px, 10);
      }
    },
    toDataURL : function() {},
    addEventListener : function() {}
  };
  return canvas;
};

var document = {
  getElementById : function(id) {
    if (id === "console") {
      return {
        appendChild : function() {}
      }
    } else {
      return newCanvas();
    }
  },
  createElement : function() {
    return newCanvas();
  }
};
var timer = false;
var window = this;

window.document = document;
window.setInterval = function(fn) {
  timer = true;
  while(timer) { fn(); }
};
window.clearInterval = function() {
  timer = false;
};
window.setTimeout = function(fn) {
  try {
    fn();
  } catch (e) {
    console.log("ERROR", e);
  }
};

// workaround for global code in array-unit-tests.html
window.array = {};

window.addEventListener = function(ev, fn) {
  fn();
};

window.scrollBy = function() {};

var XMLHttpRequest = window.XMLHttpRequest = function() {

};
XMLHttpRequest.prototype = {
  _file : null,
  open : function(method, file, async) {
    this._file = 'test/khronos-tests/conformance/' + file;
  },
  send : function() {
    this.responseText = readfile(this._file);
    this.readyState = 4;
    if (this.onreadystatechange) {
      this.onreadystatechange();
    }
    return this.responseText;
  },

};

window.parent = window;


var testFailed = function(msg) {
  webgl_test.fail = msg;
  var e = new Error();
  var parts = e.stack.split('\n');
  parts.shift();
  parts.length=10;
  parts[0] = parts[0].replace('test/runner.js', currentFile);
  webgl_test.stack = parts.join('\n');
};
var shouldBe = function(should, be, msg) {
  if (should !== be) {
    testFailed(msg);
  }
};
function finishTest() {
  console.log("test is done!");
}

testPassed = function(msg) {
  webgl_test.pass = true;
}


var sax = require('test/util/sax.js');
var webgl_tests = [];
var shaders = {};
function next_test(filename) {
  var text = readfile('test/khronos-tests/conformance/' + filename);
  var parser = sax.parser();

  parser.onerror = function (e) {
    console.log('PARSE ERROR', filename, e);
  };

  var text = text.replace(/([a-z_]*) (<)/ig,'$1 &lt;');
  var collectText = false;
  var testBody = "";

  parser.ontext = function (t) {
    if (collectText) {
      collectText(t);
    }
  };

  parser.onopentag = function (node) {
    collectText = false;

    if (node.name === "SCRIPT") {
      // TODO: shaders
      // collect the main test body
      if (!node.attributes.src) {
        testBody = "";
        collectText = function(t) {
          testBody+=t;
        }
      } else if (1==0) {//node.attributes.type.toLowerCase().indexOf('shader')) {
        console.log("here");
      };
    }
  };

  parser.onclosetag = function() {
    collectText = false;
  }

  parser.onend = function () {
    webgl_test = {
      file : filename
    };

    function description(val) {
      webgl_test.name = val;
    }

    var log = console.log;
    var error = console.error;
    var debug = console.log;

    webgl_tests.push(webgl_test);
    testBody = testBody.replace(/&lt;/g,'<');
    // run the test
    try {
      eval(testBody);
    } catch (e) {
      var split = e.stack.split('\n');
      split.length = 10;
      e.stack = split.join('\n');
      console.log(filename, e.fileName, e.lineNumber, e.message, e.stack);
      webgl_test.error = e;
      webgl_test.file = filename;
    }

    if (!isTestPassing(webgl_test)) {
      final();
      //fail();
      //return;
    }

    run_next_test();
  };

  parser.write(text).close();
}

next_test(testFiles[currentFile]);

function run_next_test() {
  currentFile++;

  if (testFiles && testFiles[currentFile]) {
    if (testFiles[currentFile].indexOf('.txt') !== -1) {
      testFiles.splice(currentFile, 1);
      currentFile--;
      return run_next_test();
    }
    if (testFiles[currentFile].substr(0,1) === '#') {
      webgl_tests.push({
        skipped : true,
        file : testFiles[currentFile]
      });
      return run_next_test();
    }
  }

  if (currentFile < testFiles.length) {
    next_test(testFiles[currentFile]);
  } else {
    final();
  }
}

function final() {
  var passes = 0;
  webgl_tests.forEach(function(test) {
    if (!isTestPassing(test)) {

      if (test.skipped) {
        console.log('# -', test.file, '(skipped)');
      } else if (!test.error) {
        console.log('✖ -', test.name + '@' + test.file, test.fail);
        console.log(test.stack);
      } else {
        var stackParts = test.error.stack.split('\n');
        stackParts.length = 5;
        test.error.stack = stackParts.join('\n    ')

        console.log('✖ -', test.name + '@' + test.file, '-', test.error.message);
        console.log('\n    ' + test.error.stack + '\n');
      }
    } else {
      passes++;
      console.log('√- ' + test.file + " (" + test.name + ")");
    }
  });


  console.log(passes + '/' + webgl_tests.length,'passed', ((passes/webgl_tests.length)*100 + '').substr(0,5) + '%');
}
