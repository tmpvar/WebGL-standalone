#ifndef _INCLUDE_Spidermonkey_
#define _INCLUDE_Spidermonkey_

  #include "../../deps/spidermonkey/js/src/jsapi.h"
  #include "../../deps/spidermonkey/js/src/jstypedarray.h"
  #include "../arch/wrapper.h"

  JSBool webgl_rendering_context_getContextAttributes(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_isContextLost(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getSupportedExtensions(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_getExtension(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_activeTexture(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_attachShader(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_bindAttribLocation(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_bindBuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_bindFramebuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_bindRenderbuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_bindTexture(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_blendColor(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_blendEquation(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_blendEquationSeparate(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_blendFunc(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_blendFuncSeparate(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_bufferData(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_bufferSubData(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_bufferSubData(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_checkFramebufferStatus(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_clear(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_clearColor(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_clearDepth(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_clearStencil(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_colorMask(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_compileShader(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_copyTexImage2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_copyTexSubImage2D(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_createBuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_createFramebuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_createProgram(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_createRenderbuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_createShader(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_createTexture(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_cullFace(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_deleteBuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_deleteFramebuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_deleteProgram(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_deleteRenderbuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_deleteShader(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_deleteTexture(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_depthFunc(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_depthMask(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_depthRange(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_detachShader(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_disable(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_disableVertexAttribArray(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_drawArrays(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_drawElements(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_enable(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_enableVertexAttribArray(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_finish(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_flush(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_framebufferRenderbuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_framebufferTexture2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_frontFace(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_generateMipmap(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getActiveAttrib(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_getActiveUniform(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_getAttachedShaders(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getAttribLocation(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getParameter(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_getBufferParameter(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getError(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getFramebufferAttachmentParameter(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_getProgramParameter(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_getProgramInfoLog(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_getRenderbufferParameter(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_getShaderParameter(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_getShaderInfoLog(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getShaderSource(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getTexParameter(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getUniform(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getUniformLocation(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getVertexAttrib(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_getVertexAttribOffset(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_hint(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_isBuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_isEnabled(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_isFramebuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_isProgram(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_isRenderbuffer(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_isShader(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_isTexture(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_lineWidth(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_linkProgram(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_pixelStorei(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_polygonOffset(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_readPixels(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_renderbufferStorage(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_sampleCoverage(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_scissor(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_shaderSource(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_stencilFunc(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_stencilFuncSeparate(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_stencilMask(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_stencilMaskSeparate(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_stencilOp(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_stencilOpSeparate(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_texImage2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_texImage2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_texImage2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_texImage2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_texImage2D(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_texParameterf(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_texParameteri(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_texSubImage2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_texSubImage2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_texSubImage2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_texSubImage2D(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_texSubImage2D(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_uniform1f(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform1fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform1fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform1i(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform1iv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform1iv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform2f(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform2fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform2fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform2i(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform2iv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform2iv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform3f(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform3fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform3fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform3i(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform3iv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform3iv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform4f(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform4fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform4fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform4i(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform4iv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniform4iv(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_uniformMatrix2fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniformMatrix2fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniformMatrix3fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniformMatrix3fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniformMatrix4fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_uniformMatrix4fv(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_useProgram(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_validateProgram(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_vertexAttrib1f(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib1fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib1fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib2f(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib2fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib2fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib3f(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib3fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib3fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib4f(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib4fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttrib4fv(JSContext *cx, uintN argc, jsval *argv);
  JSBool webgl_rendering_context_vertexAttribPointer(JSContext *cx, uintN argc, jsval *argv);

  JSBool webgl_rendering_context_viewport(JSContext *cx, uintN argc, jsval *argv);
#endif