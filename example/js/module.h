#include "jsapi.h"

char *getFileContents(const char *filename);
JSBool module_require(JSContext *cx, uintN argc, jsval *argv);