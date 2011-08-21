/*
 * This define is for Windows only, it is a work-around for bug 661663.
 */
#ifdef _MSC_VER
# define XP_WIN
#endif

/* Include the JSAPI header file to get access to SpiderMonkey. */
#include "../../src/js/spidermonkey.h"
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
JSRuntime *rt = NULL;
JSContext *cx = NULL;
JSObject  *global = NULL;

void c_exit(int code) {
  if (cx != NULL) {
    JS_DestroyContext(cx);
  }

  if (rt != NULL) {
    JS_DestroyRuntime(rt);
  }

  if (global != NULL) {
    JS_ShutDown();
  }

  exit(code);
}

JSBool js_get_file_contents(JSContext *cx, uintN argc, jsval *argv) {
  JSString *filename_string;

  if (!JS_ConvertArguments(cx, argc, JS_ARGV(cx, argv), "S", &filename_string)) {
    return JS_FALSE;
  }

  const char *filename = JS_EncodeString(cx, filename_string);

  char *file_contents_char = getFileContents(filename);
  if (file_contents_char == NULL) {
    return JS_FALSE;
  }

  JSString *fileContents  = JS_NewStringCopyN(cx, file_contents_char, strlen(file_contents_char));
  delete []file_contents_char;
  JS_SET_RVAL(cx, argv, STRING_TO_JSVAL(fileContents));
  return JS_TRUE;
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
  JS_FS("module_require",   module_require, 1, 0),
  JS_FS("stdout_print",   stdout_print, 1, 0),
  JS_FS("fail",   js_abort, 1, 0),
  JS_FS("readfile",   js_get_file_contents, 1, 0),
  JS_FS("webgl_rendering_context_getContextAttributes", webgl_rendering_context_getContextAttributes, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_isContextLost", webgl_rendering_context_isContextLost, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_getSupportedExtensions", webgl_rendering_context_getSupportedExtensions, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_getExtension", webgl_rendering_context_getExtension, 1 /* DOMString name */, 0),
  JS_FS("webgl_rendering_context_activeTexture", webgl_rendering_context_activeTexture, 1 /* GLenum texture */, 0),
  JS_FS("webgl_rendering_context_attachShader", webgl_rendering_context_attachShader, 2 /* WebGLProgram program, WebGLShader shader */, 0),
  JS_FS("webgl_rendering_context_bindAttribLocation", webgl_rendering_context_bindAttribLocation, 3 /* WebGLProgram program, GLuint index, DOMString name */, 0),
  JS_FS("webgl_rendering_context_bindBuffer", webgl_rendering_context_bindBuffer, 2 /* GLenum target, WebGLBuffer buffer */, 0),
  JS_FS("webgl_rendering_context_bindFramebuffer", webgl_rendering_context_bindFramebuffer, 2 /* GLenum target, WebGLFramebuffer framebuffer */, 0),
  JS_FS("webgl_rendering_context_bindRenderbuffer", webgl_rendering_context_bindRenderbuffer, 2 /* GLenum target, WebGLRenderbuffer renderbuffer */, 0),
  JS_FS("webgl_rendering_context_bindTexture", webgl_rendering_context_bindTexture, 2 /* GLenum target, WebGLTexture texture */, 0),
  JS_FS("webgl_rendering_context_blendColor", webgl_rendering_context_blendColor, 4 /* GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha */, 0),
  JS_FS("webgl_rendering_context_blendEquation", webgl_rendering_context_blendEquation, 1 /* GLenum mode */, 0),
  JS_FS("webgl_rendering_context_blendEquationSeparate", webgl_rendering_context_blendEquationSeparate, 2 /* GLenum modeRGB, GLenum modeAlpha */, 0),
  JS_FS("webgl_rendering_context_blendFunc", webgl_rendering_context_blendFunc, 2 /* GLenum sfactor, GLenum dfactor */, 0),
  JS_FS("webgl_rendering_context_blendFuncSeparate", webgl_rendering_context_blendFuncSeparate, 4 /* GLenum srcRGB, GLenum dstRGB,  GLenum srcAlpha, GLenum dstAlpha */, 0),
  JS_FS("webgl_rendering_context_bufferData", webgl_rendering_context_bufferData, 3, 0),
  JS_FS("webgl_rendering_context_bufferSubData", webgl_rendering_context_bufferSubData, 3 /* GLenum target, GLintptr offset, ArrayBufferView data */, 0),
  JS_FS("webgl_rendering_context_bufferSubData", webgl_rendering_context_bufferSubData, 3 /* GLenum target, GLintptr offset, ArrayBuffer data */, 0),
  JS_FS("webgl_rendering_context_checkFramebufferStatus", webgl_rendering_context_checkFramebufferStatus, 1 /* GLenum target */, 0),
  JS_FS("webgl_rendering_context_clear", webgl_rendering_context_clear, 1 /* GLbitfield mask */, 0),
  JS_FS("webgl_rendering_context_clearColor", webgl_rendering_context_clearColor, 4 /* GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha */, 0),
  JS_FS("webgl_rendering_context_clearDepth", webgl_rendering_context_clearDepth, 1 /* GLclampf depth */, 0),
  JS_FS("webgl_rendering_context_clearStencil", webgl_rendering_context_clearStencil, 1 /* GLint s */, 0),
  JS_FS("webgl_rendering_context_colorMask", webgl_rendering_context_colorMask, 4 /* GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha */, 0),
  JS_FS("webgl_rendering_context_compileShader", webgl_rendering_context_compileShader, 1 /* WebGLShader shader */, 0),
  JS_FS("webgl_rendering_context_copyTexImage2D", webgl_rendering_context_copyTexImage2D, 8 /* GLenum target, GLint level, GLenum internalformat,  GLint x, GLint y, GLsizei width, GLsizei height,   GLint border */, 0),
  JS_FS("webgl_rendering_context_copyTexSubImage2D", webgl_rendering_context_copyTexSubImage2D, 8 /* GLenum target, GLint level, GLint xoffset, GLint yoffset,  GLint x, GLint y, GLsizei width, GLsizei height */, 0),
  JS_FS("webgl_rendering_context_createBuffer", webgl_rendering_context_createBuffer, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_createFramebuffer", webgl_rendering_context_createFramebuffer, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_createProgram", webgl_rendering_context_createProgram, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_createRenderbuffer", webgl_rendering_context_createRenderbuffer, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_createShader", webgl_rendering_context_createShader, 1 /* GLenum type */, 0),
  JS_FS("webgl_rendering_context_createTexture", webgl_rendering_context_createTexture, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_cullFace", webgl_rendering_context_cullFace, 1 /* GLenum mode */, 0),
  JS_FS("webgl_rendering_context_deleteBuffer", webgl_rendering_context_deleteBuffer, 1 /* WebGLBuffer buffer */, 0),
  JS_FS("webgl_rendering_context_deleteFramebuffer", webgl_rendering_context_deleteFramebuffer, 1 /* WebGLFramebuffer framebuffer */, 0),
  JS_FS("webgl_rendering_context_deleteProgram", webgl_rendering_context_deleteProgram, 1 /* WebGLProgram program */, 0),
  JS_FS("webgl_rendering_context_deleteRenderbuffer", webgl_rendering_context_deleteRenderbuffer, 1 /* WebGLRenderbuffer renderbuffer */, 0),
  JS_FS("webgl_rendering_context_deleteShader", webgl_rendering_context_deleteShader, 1 /* WebGLShader shader */, 0),
  JS_FS("webgl_rendering_context_deleteTexture", webgl_rendering_context_deleteTexture, 1 /* WebGLTexture texture */, 0),
  JS_FS("webgl_rendering_context_depthFunc", webgl_rendering_context_depthFunc, 1 /* GLenum func */, 0),
  JS_FS("webgl_rendering_context_depthMask", webgl_rendering_context_depthMask, 1 /* GLboolean flag */, 0),
  JS_FS("webgl_rendering_context_depthRange", webgl_rendering_context_depthRange, 2 /* GLclampf zNear, GLclampf zFar */, 0),
  JS_FS("webgl_rendering_context_detachShader", webgl_rendering_context_detachShader, 2 /* WebGLProgram program, WebGLShader shader */, 0),
  JS_FS("webgl_rendering_context_disable", webgl_rendering_context_disable, 1 /* GLenum cap */, 0),
  JS_FS("webgl_rendering_context_disableVertexAttribArray", webgl_rendering_context_disableVertexAttribArray, 1 /* GLuint index */, 0),
  JS_FS("webgl_rendering_context_drawArrays", webgl_rendering_context_drawArrays, 3 /* GLenum mode, GLint first, GLsizei count */, 0),
  JS_FS("webgl_rendering_context_drawElements", webgl_rendering_context_drawElements, 4 /* GLenum mode, GLsizei count, GLenum type, GLintptr offset */, 0),
  JS_FS("webgl_rendering_context_enable", webgl_rendering_context_enable, 1 /* GLenum cap */, 0),
  JS_FS("webgl_rendering_context_enableVertexAttribArray", webgl_rendering_context_enableVertexAttribArray, 1 /* GLuint index */, 0),
  JS_FS("webgl_rendering_context_finish", webgl_rendering_context_finish, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_flush", webgl_rendering_context_flush, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_framebufferRenderbuffer", webgl_rendering_context_framebufferRenderbuffer, 4 /* GLenum target, GLenum attachment,  GLenum renderbuffertarget,                  WebGLRenderbuffer renderbuffer */, 0),
  JS_FS("webgl_rendering_context_framebufferTexture2D", webgl_rendering_context_framebufferTexture2D, 5 /* GLenum target, GLenum attachment, GLenum textarget,  WebGLTexture texture, GLint level */, 0),
  JS_FS("webgl_rendering_context_frontFace", webgl_rendering_context_frontFace, 1 /* GLenum mode */, 0),
  JS_FS("webgl_rendering_context_generateMipmap", webgl_rendering_context_generateMipmap, 1 /* GLenum target */, 0),
  JS_FS("webgl_rendering_context_getActiveAttrib", webgl_rendering_context_getActiveAttrib, 2 /* WebGLProgram program, GLuint index */, 0),
  JS_FS("webgl_rendering_context_getActiveUniform", webgl_rendering_context_getActiveUniform, 2 /* WebGLProgram program, GLuint index */, 0),
  JS_FS("webgl_rendering_context_getAttachedShaders", webgl_rendering_context_getAttachedShaders, 1 /* WebGLProgram program */, 0),
  JS_FS("webgl_rendering_context_getAttribLocation", webgl_rendering_context_getAttribLocation, 2 /* WebGLProgram program, DOMString name */, 0),
  JS_FS("webgl_rendering_context_getParameter", webgl_rendering_context_getParameter, 1 /* GLenum pname */, 0),
  JS_FS("webgl_rendering_context_getBufferParameter", webgl_rendering_context_getBufferParameter, 2 /* GLenum target, GLenum pname */, 0),
  JS_FS("webgl_rendering_context_getError", webgl_rendering_context_getError, 0 /*  */, 0),
  JS_FS("webgl_rendering_context_getFramebufferAttachmentParameter", webgl_rendering_context_getFramebufferAttachmentParameter, 3 /* GLenum target, GLenum attachment,  GLenum pname */, 0),
  JS_FS("webgl_rendering_context_getProgramParameter", webgl_rendering_context_getProgramParameter, 2 /* WebGLProgram program, GLenum pname */, 0),
  JS_FS("webgl_rendering_context_getProgramInfoLog", webgl_rendering_context_getProgramInfoLog, 1 /* WebGLProgram program */, 0),
  JS_FS("webgl_rendering_context_getRenderbufferParameter", webgl_rendering_context_getRenderbufferParameter, 2 /* GLenum target, GLenum pname */, 0),
  JS_FS("webgl_rendering_context_getShaderParameter", webgl_rendering_context_getShaderParameter, 2 /* WebGLShader shader, GLenum pname */, 0),
  JS_FS("webgl_rendering_context_getShaderInfoLog", webgl_rendering_context_getShaderInfoLog, 1 /* WebGLShader shader */, 0),
  JS_FS("webgl_rendering_context_getShaderSource", webgl_rendering_context_getShaderSource, 1 /* WebGLShader shader */, 0),
  JS_FS("webgl_rendering_context_getTexParameter", webgl_rendering_context_getTexParameter, 2 /* GLenum target, GLenum pname */, 0),
  JS_FS("webgl_rendering_context_getUniform", webgl_rendering_context_getUniform, 2 /* WebGLProgram program, WebGLUniformLocation location */, 0),
  JS_FS("webgl_rendering_context_getUniformLocation", webgl_rendering_context_getUniformLocation, 2 /* WebGLProgram program, DOMString name */, 0),
  JS_FS("webgl_rendering_context_getVertexAttrib", webgl_rendering_context_getVertexAttrib, 2 /* GLuint index, GLenum pname */, 0),
  JS_FS("webgl_rendering_context_getVertexAttribOffset", webgl_rendering_context_getVertexAttribOffset, 2 /* GLuint index, GLenum pname */, 0),
  JS_FS("webgl_rendering_context_hint", webgl_rendering_context_hint, 2 /* GLenum target, GLenum mode */, 0),
  JS_FS("webgl_rendering_context_isBuffer", webgl_rendering_context_isBuffer, 1 /* WebGLBuffer buffer */, 0),
  JS_FS("webgl_rendering_context_isEnabled", webgl_rendering_context_isEnabled, 1 /* GLenum cap */, 0),
  JS_FS("webgl_rendering_context_isFramebuffer", webgl_rendering_context_isFramebuffer, 1 /* WebGLFramebuffer framebuffer */, 0),
  JS_FS("webgl_rendering_context_isProgram", webgl_rendering_context_isProgram, 1 /* WebGLProgram program */, 0),
  JS_FS("webgl_rendering_context_isRenderbuffer", webgl_rendering_context_isRenderbuffer, 1 /* WebGLRenderbuffer renderbuffer */, 0),
  JS_FS("webgl_rendering_context_isShader", webgl_rendering_context_isShader, 1 /* WebGLShader shader */, 0),
  JS_FS("webgl_rendering_context_isTexture", webgl_rendering_context_isTexture, 1 /* WebGLTexture texture */, 0),
  JS_FS("webgl_rendering_context_lineWidth", webgl_rendering_context_lineWidth, 1 /* GLfloat width */, 0),
  JS_FS("webgl_rendering_context_linkProgram", webgl_rendering_context_linkProgram, 1 /* WebGLProgram program */, 0),
  JS_FS("webgl_rendering_context_pixelStorei", webgl_rendering_context_pixelStorei, 1 /* GLenum pname, GLint param */, 0),
  JS_FS("webgl_rendering_context_polygonOffset", webgl_rendering_context_polygonOffset, 2 /* GLfloat factor, GLfloat units */, 0),
  JS_FS("webgl_rendering_context_readPixels", webgl_rendering_context_readPixels, 7 /* GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView pixels */, 0),
  JS_FS("webgl_rendering_context_renderbufferStorage", webgl_rendering_context_renderbufferStorage, 4 /* GLenum target, GLenum internalformat, GLsizei width, GLsizei height */, 0),
  JS_FS("webgl_rendering_context_sampleCoverage", webgl_rendering_context_sampleCoverage, 2 /* GLclampf value, GLboolean invert */, 0),
  JS_FS("webgl_rendering_context_scissor", webgl_rendering_context_scissor, 4 /* GLint x, GLint y, GLsizei width, GLsizei height */, 0),
  JS_FS("webgl_rendering_context_shaderSource", webgl_rendering_context_shaderSource, 2 /* WebGLShader shader, DOMString source */, 0),
  JS_FS("webgl_rendering_context_stencilFunc", webgl_rendering_context_stencilFunc, 3 /* GLenum func, GLint ref, GLuint mask */, 0),
  JS_FS("webgl_rendering_context_stencilFuncSeparate", webgl_rendering_context_stencilFuncSeparate, 4 /* GLenum face, GLenum func, GLint ref, GLuint mask */, 0),
  JS_FS("webgl_rendering_context_stencilMask", webgl_rendering_context_stencilMask, 1 /* GLuint mask */, 0),
  JS_FS("webgl_rendering_context_stencilMaskSeparate", webgl_rendering_context_stencilMaskSeparate, 2 /* GLenum face, GLuint mask */, 0),
  JS_FS("webgl_rendering_context_stencilOp", webgl_rendering_context_stencilOp, 3 /* GLenum fail, GLenum zfail, GLenum zpass */, 0),
  JS_FS("webgl_rendering_context_stencilOpSeparate", webgl_rendering_context_stencilOpSeparate, 4 /* GLenum face, GLenum fail, GLenum zfail, GLenum zpass */, 0),
  JS_FS("webgl_rendering_context_texImage2D", webgl_rendering_context_texImage2D, 9 /* GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, ArrayBufferView pixels */, 0),
  JS_FS("webgl_rendering_context_texParameterf", webgl_rendering_context_texParameterf, 3 /* GLenum target, GLenum pname, GLfloat param */, 0),
  JS_FS("webgl_rendering_context_texParameteri", webgl_rendering_context_texParameteri, 3 /* GLenum target, GLenum pname, GLint param */, 0),
  JS_FS("webgl_rendering_context_texSubImage2D", webgl_rendering_context_texSubImage2D, 7 /* GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLVideoElement video) raises (DOMException */, 0),
  JS_FS("webgl_rendering_context_uniform1f", webgl_rendering_context_uniform1f, 2 /* WebGLUniformLocation location, GLfloat x */, 0),
  JS_FS("webgl_rendering_context_uniform1fv", webgl_rendering_context_uniform1fv, 2 /* WebGLUniformLocation location, sequence<float> v */, 0),
  JS_FS("webgl_rendering_context_uniform1i", webgl_rendering_context_uniform1i, 2 /* WebGLUniformLocation location, GLint x */, 0),
  JS_FS("webgl_rendering_context_uniform1iv", webgl_rendering_context_uniform1iv, 2 /* WebGLUniformLocation location, sequence<long> v */, 0),
  JS_FS("webgl_rendering_context_uniform2f", webgl_rendering_context_uniform2f, 3 /* WebGLUniformLocation location, GLfloat x, GLfloat y */, 0),
  JS_FS("webgl_rendering_context_uniform2fv", webgl_rendering_context_uniform2fv, 2 /* WebGLUniformLocation location, FloatArray v */, 0),
  JS_FS("webgl_rendering_context_uniform2i", webgl_rendering_context_uniform2i, 3 /* WebGLUniformLocation location, GLint x, GLint y */, 0),
  JS_FS("webgl_rendering_context_uniform2iv", webgl_rendering_context_uniform2iv, 2 /* WebGLUniformLocation location, sequence<long> v */, 0),
  JS_FS("webgl_rendering_context_uniform3f", webgl_rendering_context_uniform3f, 4 /* WebGLUniformLocation location, GLfloat x, GLfloat y, GLfloat z */, 0),
  JS_FS("webgl_rendering_context_uniform3fv", webgl_rendering_context_uniform3fv, 2 /* WebGLUniformLocation location, sequence<float> v */, 0),
  JS_FS("webgl_rendering_context_uniform3i", webgl_rendering_context_uniform3i, 4 /* WebGLUniformLocation location, GLint x, GLint y, GLint z */, 0),
  JS_FS("webgl_rendering_context_uniform3iv", webgl_rendering_context_uniform3iv, 2 /* WebGLUniformLocation location, sequence<long> v */, 0),
  JS_FS("webgl_rendering_context_uniform4f", webgl_rendering_context_uniform4f, 5 /* WebGLUniformLocation location, GLfloat x, GLfloat y, GLfloat z, GLfloat w */, 0),
  JS_FS("webgl_rendering_context_uniform4fv", webgl_rendering_context_uniform4fv, 2 /* WebGLUniformLocation location, sequence<float> v */, 0),
  JS_FS("webgl_rendering_context_uniform4i", webgl_rendering_context_uniform4i, 5 /* WebGLUniformLocation location, GLint x, GLint y, GLint z, GLint w */, 0),
  JS_FS("webgl_rendering_context_uniform4iv", webgl_rendering_context_uniform4iv, 2 /* WebGLUniformLocation location, sequence<long> v */, 0),
  JS_FS("webgl_rendering_context_uniformMatrix2fv", webgl_rendering_context_uniformMatrix2fv, 3 /* WebGLUniformLocation location, GLboolean transpose, FloatArray value */, 0),
  JS_FS("webgl_rendering_context_uniformMatrix3fv", webgl_rendering_context_uniformMatrix3fv, 3 /* WebGLUniformLocation location, GLboolean transpose, FloatArray value */, 0),
  JS_FS("webgl_rendering_context_uniformMatrix4fv", webgl_rendering_context_uniformMatrix4fv, 3 /* WebGLUniformLocation location, GLboolean transpose, FloatArray value */, 0),
  JS_FS("webgl_rendering_context_useProgram", webgl_rendering_context_useProgram, 1 /* WebGLProgram program */, 0),
  JS_FS("webgl_rendering_context_validateProgram", webgl_rendering_context_validateProgram, 1 /* WebGLProgram program */, 0),
  JS_FS("webgl_rendering_context_vertexAttrib1f", webgl_rendering_context_vertexAttrib1f, 2 /* GLuint indx, GLfloat x */, 0),
  JS_FS("webgl_rendering_context_vertexAttrib1fv", webgl_rendering_context_vertexAttrib1fv, 2 /* GLuint indx, sequence<float> values */, 0),
  JS_FS("webgl_rendering_context_vertexAttrib2f", webgl_rendering_context_vertexAttrib2f, 3 /* GLuint indx, GLfloat x, GLfloat y */, 0),
  JS_FS("webgl_rendering_context_vertexAttrib2fv", webgl_rendering_context_vertexAttrib2fv, 2 /* GLuint indx, FloatArray values */, 0),
  JS_FS("webgl_rendering_context_vertexAttrib3f", webgl_rendering_context_vertexAttrib3f, 4 /* GLuint indx, GLfloat x, GLfloat y, GLfloat z */, 0),
  JS_FS("webgl_rendering_context_vertexAttrib3fv", webgl_rendering_context_vertexAttrib3fv, 2 /* GLuint indx, sequence<float> values */, 0),
  JS_FS("webgl_rendering_context_vertexAttrib4f", webgl_rendering_context_vertexAttrib4f, 5 /* GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w */, 0),
  JS_FS("webgl_rendering_context_vertexAttrib4fv", webgl_rendering_context_vertexAttrib4fv, 2 /* GLuint indx, sequence<float> values */, 0),
  JS_FS("webgl_rendering_context_vertexAttribPointer", webgl_rendering_context_vertexAttribPointer, 6 /* GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset */, 0),
  JS_FS("webgl_rendering_context_viewport", webgl_rendering_context_viewport, 4 /* GLint x, GLint y, GLsizei width, GLsizei height */, 0),
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

int main(int argc, char **argv)
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

    glfwInit();

    glfwOpenWindow( 300,300, 0,0,0,0,0,0, GLFW_WINDOW );

    ok = JS_EvaluateScript(cx, global, script, strlen(script),
                           filename, lineno, &rval);

    delete [] script;

    if (rval == NULL || rval == JS_FALSE)
    c_exit(EXIT_SUCCESS);
}