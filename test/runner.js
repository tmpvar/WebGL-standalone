var currentTest = '';

function assert(value, message, e) {
  if (!!!value) {
    var shift = !e;

    e = e || (new Error());
    var stackParts = e.stack.split('\n');

    if (shift) {
      stackParts.shift();
      message = "Assertion Failure: " + message;
    }

    e.stack = stackParts.join('\n    ')

    console.log('✖ -', currentTest, '-', message);
    console.log('\n    ' + e.stack + '\n');
    fail();
  } else {
    console.log('√ - ' + currentTest);
  }
}

function run(fn) {
  currentTest = fn.name;
  try {
    fn();
  } catch (e) {
    assert(false, 'Exception: ' + e.message, e);
  }
}

var testList = readfile('test/khronos-tests/conformance/00_test_list.txt');
var testFiles = testList.split('\n');
var currentFile = 0;

var sax = require('test/util/sax.js');
var tests = [];
function next_test(filename) {
  console.log('loading', filename)
  var text = readfile('test/khronos-tests/conformance/' + filename);
  var parser = sax.parser();
  parser.onerror = function (e) {
    console.log('PARSE ERROR', e);
  };


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
    if (node.name === "SCRIPT") {
      // TODO: shaders

      // collect the main test body
      if (!node.attributes.src) {
        collectText = function(text) {
          testBody = text;
        };
      }
    }
  };

  parser.onclosetag = function() {
    collectText = false;
  }

  parser.onend = function () {
    var test = {};
    function description(val) {
      test.name = val;
    }
    function testPassed() {
      test.pass = true;
    }

    // run the test
    try {
      eval(testBody);
    } catch (e) {
      test.error = e;
      test.file = filename;
    }

    tests.push(test);
    run_next_test();
  };

  parser.write(text).close();
}

next_test(testFiles[currentFile]);

function run_next_test() {
  currentFile++;
  while (testFiles[currentFile] && testFiles[currentFile].indexOf('#') !== -1) {
    currentFile++;
  }

  if (testFiles[currentFile] && currentFile < testFiles.length) {
    next_test(testFiles[currentFile]);
  } else {
    final();
  }
}

function final() {
  tests.forEach(function(test) {
  if (!test.pass) {
    if (!test.error) {
      console.log('✖ -', test.name);
    } else {
      var stackParts = test.error.stack.split('\n');

      test.error.stack = stackParts.join('\n    ')

      console.log('✖ -', test.name || test.file, '-', test.error.message);
      console.log('\n    ' + test.error.stack + '\n');
    }
  } else {
    console.log('√ - ' + test.name);
  }
});
}
