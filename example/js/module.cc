#include <fstream>
#include <iostream>

#include "module.h"

using namespace std;


char *getFileContents(const char *filename) {
  ifstream scriptStream(filename, ios::in);
  if (scriptStream.is_open() == false) {
    return NULL;
  }

  scriptStream.seekg(0, ios::end);
  int size = (int)scriptStream.tellg();
  if (size == 0) {
    return NULL;
  }

  scriptStream.seekg (0, ios::beg);
  char *script = new char [size+1];
  scriptStream.read(script, size);
  scriptStream.close();
  script[size] = 0;
  return script;
}


JSBool module_require(JSContext *cx, uintN argc, jsval *argv) {

  JSString *filename_string;

  JSObject *object;
  int rc;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "S", &filename_string)) {
    return JS_FALSE;
  }

  jsval false_return = BOOLEAN_TO_JSVAL(JS_FALSE);

  const char *filename = JS_EncodeString(cx, filename_string);
  cout << "WEBGL MODULE: " <<  filename << endl;
  char *script = getFileContents(filename);
  if (script == NULL) {
    JS_SET_RVAL(cx, argv, false_return);
    return JS_FALSE;
  }

  JSObject *scriptObject = JS_NewObject(cx, NULL, NULL, NULL);
  const char *args[5] = {
    "exports", "require", "module", "__filename", "__dirname"
  };

  JSFunction *wrapper = JS_CompileFunction(cx, scriptObject, "require_wrapper", 5, args, script, strlen(script), filename, 0);
  delete [] script;

  if (wrapper == NULL) {
    JS_SET_RVAL(cx, argv, false_return);
    return JS_FALSE;
  }

  JSObject *function = JS_GetFunctionObject(wrapper);
  if (function == NULL) {
    JS_SET_RVAL(cx, argv, false_return);
    return JS_FALSE;
  }

  JS_SET_RVAL(cx, argv, OBJECT_TO_JSVAL(function));
  return JS_TRUE;
}
