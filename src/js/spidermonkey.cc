#include "spidermonkey.h"
#include "../arch/wrapper.h"

JSBool webgl_rendering_context_getContextAttributes(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_isContextLost(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_getSupportedExtensions(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_getExtension(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_activeTexture(JSContext *cx, uintN argc, jsval *argv) {
  GLuint texture;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &texture)) {
    return JS_FALSE;
  }

  glActiveTexture(texture);

  return JS_TRUE;
}

JSBool webgl_rendering_context_attachShader(JSContext *cx, uintN argc, jsval *argv) {

  GLuint program;
  GLuint shader;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uu", &program, &shader)) {
    return JS_FALSE;
  }

  glAttachShader(program, shader);

  return JS_TRUE;
}

JSBool webgl_rendering_context_bindAttribLocation(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_bindBuffer(JSContext *cx, uintN argc, jsval *argv) {

  GLenum target;
  GLuint buffer;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uu", &target, &buffer)) {
    return JS_FALSE;
  }

  glBindBuffer(target, buffer);

  return JS_TRUE;
}

JSBool webgl_rendering_context_bindFramebuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_bindRenderbuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_bindTexture(JSContext *cx, uintN argc, jsval *argv) {

  GLenum target;
  GLuint texture;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uu", &target, &texture)) {
    JS_ReportError(cx, "Error in bindTexture");
    return JS_FALSE;
  }

  glBindTexture(target, texture);

  return JS_TRUE;
}

JSBool webgl_rendering_context_blendColor(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_blendEquation(JSContext *cx, uintN argc, jsval *argv) {
  GLuint mode;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &mode)) {
    return JS_FALSE;
  }

  glBlendEquation(mode);

  return JS_TRUE;
}

JSBool webgl_rendering_context_blendEquationSeparate(JSContext *cx, uintN argc, jsval *argv) {

  GLuint modeRGB;
  GLenum modeAlpha;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uu", &modeRGB, &modeAlpha)) {
    return JS_FALSE;
  }

  glBlendEquationSeparate(modeRGB, modeAlpha);
  return JS_TRUE;
}

JSBool webgl_rendering_context_blendFunc(JSContext *cx, uintN argc, jsval *argv) {
  GLenum sfactor;
  GLuint dfactor;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uu", &sfactor, &dfactor)) {
    JS_ReportError(cx, "Error in blendFunc");
    return JS_FALSE;
  }

  glBlendFunc(sfactor, dfactor);

  return JS_TRUE;
}

JSBool webgl_rendering_context_blendFuncSeparate(JSContext *cx, uintN argc, jsval *argv) {
  GLuint srcRGB;
  GLuint dstRGB;
  GLenum srcAlpha;
  GLenum dstAlpha;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uuuu", &srcRGB, &dstRGB, &srcAlpha, &dstAlpha)) {
    return JS_FALSE;
  }

  glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
  return JS_TRUE;
}


JSBool webgl_rendering_context_bufferData(JSContext *cx, uintN argc, jsval *argv) {
  GLenum target;
  JSObject *array;
  GLenum usage;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uou", &target, &array, &usage)) {
    return JS_FALSE;
  }

  js::TypedArray *tarray = js::TypedArray::fromJSObject(array);
  glBufferData(target, tarray->byteLength, tarray->data, usage);

  return JS_TRUE;
}

JSBool webgl_rendering_context_bufferSubData(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_checkFramebufferStatus(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_clear(JSContext *cx, uintN argc, jsval *argv) {

  GLbitfield bits;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "i", &bits)) {
    return JS_FALSE;
  }

  glClear(bits);
  return JS_TRUE;
}

JSBool webgl_rendering_context_clearColor(JSContext *cx, uintN argc, jsval *argv) {

  jsdouble r;
  jsdouble g;
  jsdouble b;
  jsdouble a;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "dddd", &r, &g, &b, &a)) {
    return JS_FALSE;
  }

  glClearColor(r,g,b,a);

  return JS_TRUE;
}

JSBool webgl_rendering_context_clearDepth(JSContext *cx, uintN argc, jsval *argv) {

  GLclampd clampd;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "d", &clampd)) {
    return JS_FALSE;
  }

  glClearDepth(clampd);

  return JS_TRUE;
}

JSBool webgl_rendering_context_clearStencil(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_colorMask(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_compileShader(JSContext *cx, uintN argc, jsval *argv) {

  GLuint id;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &id)) {
    return JS_FALSE;
  }

  glCompileShader(id);

  return JS_TRUE;
}


JSBool webgl_rendering_context_copyTexImage2D(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_copyTexSubImage2D(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_createBuffer(JSContext *cx, uintN argc, jsval *argv) {
  GLuint buffer;
  glGenBuffers(1, &buffer);
  JS_SET_RVAL(cx, argv, UINT_TO_JSVAL(buffer));
  return JS_TRUE;
}

JSBool webgl_rendering_context_createFramebuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_createProgram(JSContext *cx, uintN argc, jsval *argv) {

  GLuint ret = glCreateProgram();
  JS_SET_RVAL(cx, argv, UINT_TO_JSVAL(ret));

  return JS_TRUE;
}

JSBool webgl_rendering_context_createRenderbuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_createShader(JSContext *cx, uintN argc, jsval *argv) {

  GLenum type;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &type)) {
    return JS_FALSE;
  }

  GLuint ret = glCreateShader(type);
  JS_SET_RVAL(cx, argv, UINT_TO_JSVAL(ret));

  return JS_TRUE;
}

JSBool webgl_rendering_context_createTexture(JSContext *cx, uintN argc, jsval *argv) {
  GLuint ret;
  glGenTextures(1, &ret);
  JS_SET_RVAL(cx, argv, UINT_TO_JSVAL(ret));
  return JS_TRUE;
}


JSBool webgl_rendering_context_cullFace(JSContext *cx, uintN argc, jsval *argv) {
  GLuint mode;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &mode)) {
    return JS_FALSE;
  }

  glCullFace(mode);

  return JS_TRUE;
}


JSBool webgl_rendering_context_deleteBuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_deleteFramebuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_deleteProgram(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_deleteRenderbuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_deleteShader(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_deleteTexture(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_depthFunc(JSContext *cx, uintN argc, jsval *argv) {

  GLuint func;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &func)) {
    return JS_FALSE;
  }

  glDepthFunc(func);

  return JS_TRUE;
}

JSBool webgl_rendering_context_depthMask(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_depthRange(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_detachShader(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_disable(JSContext *cx, uintN argc, jsval *argv) {
  GLenum cap;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &cap)) {
    JS_ReportError(cx, "Error in blendFunc");
    return JS_FALSE;
  }

  glDisable(cap);

  return JS_TRUE;
}

JSBool webgl_rendering_context_disableVertexAttribArray(JSContext *cx, uintN argc, jsval *argv) {

  GLuint attr;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &attr)) {
    return JS_FALSE;
  }

  glDisableVertexAttribArray(attr);

  return JS_TRUE;
}

JSBool webgl_rendering_context_drawArrays(JSContext *cx, uintN argc, jsval *argv) {

  GLenum mode;
  GLint first;
  GLsizei count;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uii", &mode, &first, &count)) {
    return JS_FALSE;
  }

  glDrawArrays(mode, first, count);

  return JS_TRUE;
}

JSBool webgl_rendering_context_drawElements(JSContext *cx, uintN argc, jsval *argv) {

  GLenum mode;
  GLsizei count;
  GLenum type;
  GLint offset;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uiui", &mode, &count, &type, &offset)) {
    return JS_FALSE;
  }

  glDrawElements(mode, count, type, (void *)offset);

  return JS_TRUE;
}


JSBool webgl_rendering_context_enable(JSContext *cx, uintN argc, jsval *argv) {

  GLuint bits;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &bits)) {
    return JS_FALSE;
  }

  glEnable(bits);

  return JS_TRUE;
}

JSBool webgl_rendering_context_enableVertexAttribArray(JSContext *cx, uintN argc, jsval *argv) {

  GLuint attr;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &attr)) {
    return JS_FALSE;
  }

  glEnableVertexAttribArray(attr);

  return JS_TRUE;
}

JSBool webgl_rendering_context_finish(JSContext *cx, uintN argc, jsval *argv) {
  glFinish();
  return JS_TRUE;
}

JSBool webgl_rendering_context_flush(JSContext *cx, uintN argc, jsval *argv) {
  // TODO: make this more flexible?
  // Swap front and back rendering buffers
  glfwSwapBuffers();
  return JS_TRUE;
}

JSBool webgl_rendering_context_framebufferRenderbuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_framebufferTexture2D(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_frontFace(JSContext *cx, uintN argc, jsval *argv) {
  GLuint mode;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &mode)) {
    return JS_FALSE;
  }

  glFrontFace(mode);

  return JS_TRUE;
}


JSBool webgl_rendering_context_generateMipmap(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_getActiveAttrib(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_getActiveUniform(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_getAttachedShaders(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_getAttribLocation(JSContext *cx, uintN argc, jsval *argv) {

  GLuint program;
  JSString *js_attr;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uS", &program, &js_attr)) {
    return JS_FALSE;
  }

  const char *attr = JS_EncodeString(cx, js_attr);
  GLint ret = glGetAttribLocation(program, attr);
  JS_free(cx, (void *)attr);

  JS_SET_RVAL(cx, argv, INT_TO_JSVAL(ret));
  return JS_TRUE;
}


JSBool webgl_rendering_context_getParameter(JSContext *cx, uintN argc, jsval *argv) {

  GLenum name;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &name)) {
    return JS_FALSE;
  }

  const char *value = (const char *)glGetString(name);

  if (value == 0) {
    // DANGER!
    JSString *js_value  = JS_NewStringCopyN(cx, "", 0);
    JS_SET_RVAL(cx, argv, STRING_TO_JSVAL(js_value));

  } else {
    // DANGER!
    JSString *js_value  = JS_NewStringCopyN(cx, value, strlen(value));
    JS_SET_RVAL(cx, argv, STRING_TO_JSVAL(js_value));
  }

  return JS_TRUE;
}

JSBool webgl_rendering_context_getBufferParameter(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_getError(JSContext *cx, uintN argc, jsval *argv) {
  JS_SET_RVAL(cx, argv, UINT_TO_JSVAL(glGetError()));
  return JS_TRUE;
}


JSBool webgl_rendering_context_getFramebufferAttachmentParameter(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_getProgramParameter(JSContext *cx, uintN argc, jsval *argv) {

  GLuint program;
  GLenum param;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uu", &program, &param)) {
    return JS_FALSE;
  }

  GLint status;
  glGetProgramiv(program, param, &status);

  switch (param) {
    case GL_DELETE_STATUS:
    case GL_LINK_STATUS:
    case GL_VALIDATE_STATUS:
      JS_SET_RVAL(cx, argv, BOOLEAN_TO_JSVAL((GLboolean)status));
    break;

    // all others are int return types
    default:
      JS_SET_RVAL(cx, argv, INT_TO_JSVAL(status));
    break;
  }

  return JS_TRUE;
}

JSBool webgl_rendering_context_getProgramInfoLog(JSContext *cx, uintN argc, jsval *argv) {

  GLuint program;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &program)) {
    return JS_FALSE;
  }

  GLint logLength = 0;
  GLsizei maxLength;

  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
  char infoLog[maxLength];

  glGetProgramInfoLog(program, maxLength, &logLength, infoLog);

  JSString *jsLogString  = JS_NewStringCopyN(cx, infoLog, logLength);
  JS_SET_RVAL(cx, argv, STRING_TO_JSVAL(jsLogString));

  return JS_TRUE;
}

JSBool webgl_rendering_context_getRenderbufferParameter(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_getShaderParameter(JSContext *cx, uintN argc, jsval *argv) {
  GLuint shader;
  GLenum pname;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uu", &shader, &pname)) {
    return JS_FALSE;
  }

  GLint param;
  glGetShaderiv(shader, pname, &param);
  JS_SET_RVAL(cx, argv, INT_TO_JSVAL(param));
  return JS_TRUE;
}

JSBool webgl_rendering_context_getShaderInfoLog(JSContext *cx, uintN argc, jsval *argv) {
  GLuint shader;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &shader)) {
    return JS_FALSE;
  }

  GLint logLength = 0;
  GLsizei maxLength;

  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
  char infoLog[maxLength];

  glGetShaderInfoLog(shader, maxLength, &logLength, infoLog);

  JSString *jsLogString  = JS_NewStringCopyN(cx, infoLog, logLength);
  JS_SET_RVAL(cx, argv, STRING_TO_JSVAL(jsLogString));

  return JS_TRUE;
}


JSBool webgl_rendering_context_getShaderSource(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_getTexParameter(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_getUniform(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_getUniformLocation(JSContext *cx, uintN argc, jsval *argv) {

  GLuint program;
  JSString *js_name;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uS", &program, &js_name)) {
    return JS_FALSE;
  }

  const char *name = JS_EncodeString(cx, js_name);

  GLint ret = glGetUniformLocation(program, name);
  JS_free(cx, (void *)name);
  JS_SET_RVAL(cx, argv, INT_TO_JSVAL(ret));

  return JS_TRUE;
}


JSBool webgl_rendering_context_getVertexAttrib(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_getVertexAttribOffset(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_hint(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_isBuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_isEnabled(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_isFramebuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_isProgram(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_isRenderbuffer(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_isShader(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_isTexture(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_lineWidth(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_linkProgram(JSContext *cx, uintN argc, jsval *argv) {

  GLuint program;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &program)) {
    return JS_FALSE;
  }

  glLinkProgram(program);

  return JS_TRUE;
}

JSBool webgl_rendering_context_pixelStorei(JSContext *cx, uintN argc, jsval *argv) {

  GLuint param;
  GLint  value;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "ui", &param, &value)) {
    return JS_FALSE;
  }

  glPixelStorei(param, value);

  return JS_TRUE;
}

JSBool webgl_rendering_context_polygonOffset(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_readPixels(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_renderbufferStorage(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_sampleCoverage(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_scissor(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_shaderSource(JSContext *cx, uintN argc, jsval *argv) {

  GLuint id;
  JSString *js_source;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uS", &id, &js_source)) {
    return JS_FALSE;
  }

  const char *source = JS_EncodeString(cx, js_source);
  int length = JS_GetStringLength(js_source);
  glShaderSource(id, 1, &source, &length);
  JS_free(cx, (void *)source);

  return JS_TRUE;
}


JSBool webgl_rendering_context_stencilFunc(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_stencilFuncSeparate(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_stencilMask(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_stencilMaskSeparate(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_stencilOp(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_stencilOpSeparate(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_texImage2D(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_texImage2D_Image(JSContext *cx, uintN argc, jsval *argv) {
  cout << "gere" << endl;
  GLenum target;
  GLint level;
  GLint internalFormat;
  GLenum format;
  GLenum type;
  JSObject *image;

/*    void texImage2D(GLenum target, GLint level, GLenum internalformat,
                    GLenum format, GLenum type, HTMLImageElement image);
*/
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uiiuuo", &target, &level, &internalFormat, &format, &type, &image)) {
    return JS_FALSE;
  }

  jsval js_width;
  if (!JS_GetProperty(cx, image, "width", &js_width)) {
    return JS_FALSE;
  }
  int width = JSVAL_TO_INT(js_width);

  jsval js_height;
  if (!JS_GetProperty(cx, image, "height", &js_height)) {
    return JS_FALSE;
  }
  int height = JSVAL_TO_INT(js_height);

  jsval js_bytesPerPixel;
  if (!JS_GetProperty(cx, image, "bytesPerPixel", &js_bytesPerPixel)) {
    return JS_FALSE;
  }
  int bytesPerPixel = JSVAL_TO_INT(js_bytesPerPixel);

  jsval js_data;
  if (!JS_GetProperty(cx, image, "data", &js_data)) {
    return JS_FALSE;
  }

  JSObject *dataObject = JSVAL_TO_OBJECT(js_data);
  js::TypedArray *tarray = js::TypedArray::fromJSObject(dataObject);

  const unsigned char *data = (unsigned char *)tarray->data;

  glTexImage2D(target, level, internalFormat, width, height, 0, format, type, data);

  return JS_TRUE;
}

JSBool webgl_rendering_context_texParameterf(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_texParameteri(JSContext *cx, uintN argc, jsval *argv) {
  GLuint target;
  GLuint pname;
  GLuint param;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uuu", &target, &pname, &param)) {
    return JS_FALSE;
  }

  glTexParameteri(target, pname, param);

  return JS_TRUE;
}

JSBool webgl_rendering_context_texSubImage2D(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_uniform1f(JSContext *cx, uintN argc, jsval *argv) {
  GLuint location;
  jsdouble x;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "ud", &location, &x)) {
    return JS_FALSE;
  }

  glUniform1f(location, x);

  return JS_TRUE;
}

JSBool webgl_rendering_context_uniform1fv(JSContext *cx, uintN argc, jsval *argv) {
  GLenum location;
  JSObject *obj;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uo", &location, &obj)) {
    return JS_FALSE;
  }

  js::TypedArray *tarray = js::TypedArray::fromJSObject(obj);
  glUniform1fv(location, tarray->length, (GLfloat *)tarray->data);

  return JS_TRUE;

}

JSBool webgl_rendering_context_uniform1i(JSContext *cx, uintN argc, jsval *argv) {
  GLuint location;
  GLint x;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "ui", &location, &x)) {
    return JS_FALSE;
  }

  glUniform1i(location, x);

  return JS_TRUE;
}

JSBool webgl_rendering_context_uniform1iv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_uniform2f(JSContext *cx, uintN argc, jsval *argv) {
  GLuint location;
  jsdouble x, y;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "udd", &location, &x, &y)) {
    return JS_FALSE;
  }

  glUniform2f(location, x, y);

  return JS_TRUE;
}

JSBool webgl_rendering_context_uniform2fv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_uniform2i(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_uniform2iv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_uniform3f(JSContext *cx, uintN argc, jsval *argv) {
  GLuint location;
  jsdouble x, y, z;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uddd", &location, &x, &y, &z)) {
    return JS_FALSE;
  }

  glUniform3f(location, x, y, z);

  return JS_TRUE;
}

JSBool webgl_rendering_context_uniform3fv(JSContext *cx, uintN argc, jsval *argv) {
  GLenum location;
  JSObject *obj;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uo", &location, &obj)) {
    return JS_FALSE;
  }

  js::TypedArray *tarray = js::TypedArray::fromJSObject(obj);
  glUniform3fv(location, tarray->length, (GLfloat *)tarray->data);

  return JS_TRUE;
}

JSBool webgl_rendering_context_uniform3i(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_uniform3iv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_uniform4f(JSContext *cx, uintN argc, jsval *argv) {
  GLuint location;
  jsdouble x, y, z, w;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uddd", &location, &x, &y, &z, &w)) {
    return JS_FALSE;
  }

  glUniform4f(location, x, y, z, w);

  return JS_TRUE;
}

JSBool webgl_rendering_context_uniform4fv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_uniform4i(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_uniform4iv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_uniformMatrix2fv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_uniformMatrix3fv(JSContext *cx, uintN argc, jsval *argv) {
  GLenum location;
  JSBool transpose;
  JSObject *array;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "ubo", &location, &transpose, &array)) {
    return JS_FALSE;
  }

  js::TypedArray *tarray = js::TypedArray::fromJSObject(array);
  glUniformMatrix3fv(location, tarray->length, (GLboolean)transpose, (GLfloat *)tarray->data);

  return JS_TRUE;
}

JSBool webgl_rendering_context_uniformMatrix4fv(JSContext *cx, uintN argc, jsval *argv) {
  GLenum location;
  JSBool transpose;
  JSObject *array;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "ubo", &location, &transpose, &array)) {
    return JS_FALSE;
  }

  js::TypedArray *tarray = js::TypedArray::fromJSObject(array);
  glUniformMatrix4fv(location, tarray->length, (GLboolean)transpose, (GLfloat *)tarray->data);

  return JS_TRUE;
}


JSBool webgl_rendering_context_useProgram(JSContext *cx, uintN argc, jsval *argv) {

  GLuint program;
  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "u", &program)) {
    return JS_FALSE;
  }

  glUseProgram(program);

  return JS_TRUE;
}

JSBool webgl_rendering_context_validateProgram(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_vertexAttrib1f(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_vertexAttrib1fv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}


JSBool webgl_rendering_context_vertexAttrib2f(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_vertexAttrib2fv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_vertexAttrib3f(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_vertexAttrib3fv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_vertexAttrib4f(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_vertexAttrib4fv(JSContext *cx, uintN argc, jsval *argv) {
  JS_ReportError(cx, "method not implemented");
  return JS_FALSE;
}

JSBool webgl_rendering_context_vertexAttribPointer(JSContext *cx, uintN argc, jsval *argv) {

  GLuint attr;
  GLint size;
  GLenum type;
  JSBool normalized;
  GLsizei stride;
  GLint offset;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "uiubii", &attr, &size, &type, &normalized, &stride, &offset)) {
    return JS_FALSE;
  }

  glVertexAttribPointer(attr, size, type, (GLboolean)normalized, stride, (void *)offset);

  return JS_TRUE;
}


JSBool webgl_rendering_context_viewport(JSContext *cx, uintN argc, jsval *argv) {

  int x;
  int y;
  int w;
  int h;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "iiii", &x, &y, &w, &h)) {
    return JS_FALSE;
  }

  glViewport(x, y, w, h);
  return JS_TRUE;
}
