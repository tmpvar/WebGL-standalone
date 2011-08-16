/*
 * This define is for Windows only, it is a work-around for bug 661663.
 */
#ifdef _MSC_VER
# define XP_WIN
#endif

/* Include the JSAPI header file to get access to SpiderMonkey. */
#include "jsapi.h"
#include "WebGL.h"
#include "module.h"
#include <stdlib.h>

/* The class of the global object. */
static JSClass global_class = {
    "global", JSCLASS_GLOBAL_FLAGS,
    JS_PropertyStub, JS_PropertyStub, JS_PropertyStub, JS_StrictPropertyStub,
    JS_EnumerateStub, JS_ResolveStub, JS_ConvertStub, JS_FinalizeStub,
    JSCLASS_NO_OPTIONAL_MEMBERS
};


/* JSAPI variables. */
JSRuntime *rt;
JSContext *cx;
JSObject  *global;

void c_exit(int code) {
  JS_DestroyContext(cx);
  JS_DestroyRuntime(rt);
  JS_ShutDown();
  exit(code);
}

JSBool js_abort(JSContext *cx, uintN argc, jsval *argv) {
  c_exit(-1);
}

JSBool stdout_print(JSContext *cx, uintN argc, jsval *argv) {
  JSString *str;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "S", &str)) {
    return JS_FALSE;
  }

  char *out = JS_EncodeString(cx, str);
  cout << out;
  free(out);

  return JS_TRUE;
}

static JSFunctionSpec module_global_functions[] = {
    //JSBool module_require(JSContext *cx, uintN argc, jsval *argv, jsval *rval);
    JS_FS("module_require",   module_require, 1, 0),
    JS_FS("stdout_print",   stdout_print, 1, 0),
    JS_FS("fail",   js_abort, 1, 0),
    JS_FS_END
};


/* The error reporter callback. */
void reportError(JSContext *cx, const char *message, JSErrorReport *report)
{
    cout << "WEBGL ERROR: "
         << report->filename
         << " line:"
         << report->lineno
         << endl
         << "\t'"
         << message
         << "'"
         << endl;
}


void setupGlobals(JSContext *cx, JSObject *global) {
  const char *globals =
  "function require(filename) {"
  "  var module = {"
  "    exports : {}"
  "  };"
  "  var parts = filename.split('/');"
  "  parts.pop();"
  "  var dirname = parts.join('/');"
  "  module_require(filename)(module.exports, require, module, filename, dirname);"
  "  return module.exports"
  "};"
  "this.console = {"
  "  log : function() {"
  "    var args = Array.prototype.slice.call(arguments);"
  "    stdout_print(args.join(' ') + '\\n');"
  "  }"
  "};";

  jsval rval;
  JSBool ok = JS_EvaluateScript(cx, global, globals, strlen(globals),
                                "require.js", 0, &rval);
  if (!ok) {
    cout << "WEBGL ERROR: There was a problem setting up require" << endl;
  }
}




int main(int argc, const char *argv[])
{
    if (argc < 2) {
        cout << "Usage: webgljs path/to/app.js" << endl;
        c_exit(EXIT_FAILURE);
    }

    const char* filename = argv[1];
    char *script = getFileContents(filename);

    /* Create a JS runtime. You always need at least one runtime per process. */
    rt = JS_NewRuntime(8 * 1024 * 1024);
    if (rt == NULL)
        c_exit(EXIT_FAILURE);

    /* Create a context. You always need a context per thread. */
    cx = JS_NewContext(rt, 8192);
    if (cx == NULL)
        c_exit(EXIT_FAILURE);

    JS_SetOptions(cx, JSOPTION_VAROBJFIX | JSOPTION_JIT | JSOPTION_METHODJIT);
    JS_SetVersion(cx, JSVERSION_LATEST);
    JS_SetErrorReporter(cx, reportError);

    global = JS_NewCompartmentAndGlobalObject(cx, &global_class, NULL);
    if (global == NULL)
        c_exit(EXIT_FAILURE);

    if (!JS_InitStandardClasses(cx, global))
        c_exit(EXIT_FAILURE);

    jsval rval;
    JSString *str;
    JSBool ok;
    uintN lineno = 0;

    if (!JS_DefineFunctions(cx, global, module_global_functions))
      c_exit(EXIT_FAILURE);

    setupGlobals(cx, global);

    ok = JS_EvaluateScript(cx, global, script, strlen(script),
                           filename, lineno, &rval);
    delete [] script;

    if (rval == NULL || rval == JS_FALSE)
    c_exit(EXIT_SUCCESS);
}