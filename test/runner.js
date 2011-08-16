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

var a = require('test/sanity-test.js');
currentTest = a.name;
run(a);