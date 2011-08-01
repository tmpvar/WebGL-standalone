/**
  WebGL Standalone
  
  WebGLRenderingContext.h
  
  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/

#include "WebGLRenderingContext.h"

WebGLRenderingContext::WebGLRenderingContext() {
  
}

WebGLRenderingContext::~WebGLRenderingContext() {
  
}

HTMLCanvasElement WebGLRenderingContext::getCanvas() {
  
}

WebGLContextAttributes* WebGLRenderingContext::getContextAttributes() {
  
}


bool WebGLRenderingContext::isContextLost() {
  return false;
}


DOMString** WebGLRenderingContext::getSupportedExtensions() {
  
}


void* WebGLRenderingContext::getExtension(DOMString *name) {
  
}

void WebGLRenderingContext::activeTexture(GLenum texture) {
  
}

void WebGLRenderingContext::attachShader(WebGLProgram *program, WebGLShader *shader) {
  assert(program);
  assert(shader);
  program->attach(shader);
}

void WebGLRenderingContext::bindAttribLocation(WebGLProgram *program, GLuint index, DOMString *name) {
  glBindAttribLocation(program->id, index, name->value.c_str());
}

void WebGLRenderingContext::bindBuffer(GLenum target, WebGLBuffer *buffer) {
  glBindBuffer(target, buffer->id);
}

void WebGLRenderingContext::bindFramebuffer(GLenum target, WebGLFramebuffer *framebuffer) {
}

void WebGLRenderingContext::bindRenderbuffer(GLenum target, WebGLRenderbuffer *renderbuffer) {
  
}

void WebGLRenderingContext::bindTexture(GLenum target, WebGLTexture *texture) {
  glBindTexture(target, texture->id);
}

void WebGLRenderingContext::blendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
  glBlendColor(red, green, blue, alpha);
}

void WebGLRenderingContext::blendEquation(GLenum mode) {
  glBlendEquation(mode);
}

void WebGLRenderingContext::blendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
  glBlendEquationSeparate(modeRGB, modeAlpha);
}

void WebGLRenderingContext::blendFunc(GLenum sfactor, GLenum dfactor) {
  glBlendFunc(sfactor, dfactor);
}

void WebGLRenderingContext::blendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
  glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void WebGLRenderingContext::bufferData(GLenum target, GLsizeiptr size, GLenum usage) {
  glBufferData(target, size, 0, usage);
}

void WebGLRenderingContext::bufferData(GLenum target, ArrayBufferView *data, GLenum usage) {
  glBufferData(target, data->length, (void *)&data, usage);
}

void WebGLRenderingContext::bufferData(GLenum target, ArrayBuffer *data, GLenum usage) {
  glBufferData(target, sizeof(GLfloat) * 12, (void *)&data->data, usage);
}

void WebGLRenderingContext::bufferSubData(GLenum target, GLintptr offset, ArrayBufferView *data) {
  
}

void WebGLRenderingContext::bufferSubData(GLenum target, GLintptr offset, ArrayBuffer *data) {
  
}

GLenum WebGLRenderingContext::checkFramebufferStatus(GLenum target) {
  
}

void WebGLRenderingContext::clear(GLbitfield mask) {
  glClear(mask);
}

void WebGLRenderingContext::clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
  glClearColor(red, green, blue, alpha);
}

void WebGLRenderingContext::clearDepth(GLclampf depth) {
  glClearDepth(depth);
}

void WebGLRenderingContext::clearStencil(GLint s) {
  glClearStencil(s);
}

void WebGLRenderingContext::colorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
  glColorMask(red, green, blue, alpha);
}

void WebGLRenderingContext::compileShader(WebGLShader *shader) {
  shader->compile();
}

void WebGLRenderingContext::copyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
  glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}

void WebGLRenderingContext::copyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
  glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

WebGLBuffer* WebGLRenderingContext::createBuffer() {
  // TODO: manage this memory
  return new WebGLBuffer();
}

WebGLFramebuffer* WebGLRenderingContext::createFramebuffer() {
  // TODO: manage this memory
  return new WebGLFramebuffer();
}

WebGLProgram* WebGLRenderingContext::createProgram() {
  // TODO: manage this memory
  return new WebGLProgram();
}

WebGLRenderbuffer* WebGLRenderingContext::createRenderbuffer() {
  // TODO: manage this memory
  return new WebGLRenderbuffer();
}

WebGLShader* WebGLRenderingContext::createShader(GLenum type) {
  // TODO: manage this memory
  return new WebGLShader(type);
}

WebGLTexture* WebGLRenderingContext::createTexture() {
  // TODO: manage this memory
  return new WebGLTexture();
}


void WebGLRenderingContext::cullFace(GLenum mode) {
  glCullFace(mode);
}

void WebGLRenderingContext::deleteBuffer(WebGLBuffer *buffer) {
  
}

void WebGLRenderingContext::deleteFramebuffer(WebGLFramebuffer *framebuffer) {
  
}

void WebGLRenderingContext::deleteProgram(WebGLProgram *program) {
  
}

void WebGLRenderingContext::deleteRenderbuffer(WebGLRenderbuffer *renderbuffer) {
  
}

void WebGLRenderingContext::deleteShader(WebGLShader *shader) {
  
}

void WebGLRenderingContext::deleteTexture(WebGLTexture *texture) {
  
}

void WebGLRenderingContext::depthFunc(GLenum func) {
  glDepthFunc(func);
}

void WebGLRenderingContext::depthMask(GLboolean flag) {
  glDepthMask(flag);
}

void WebGLRenderingContext::depthRange(GLclampf zNear, GLclampf zFar) {
  glDepthRange(zNear, zFar);
}

void WebGLRenderingContext::detachShader(WebGLProgram *program, WebGLShader *shader) {
  glDetachShader(program->id, shader->id);
}

void WebGLRenderingContext::disable(GLenum cap) {
  glDisable(cap);
}

void WebGLRenderingContext::disableVertexAttribArray(GLuint index) {
  glDisableVertexAttribArray(index);
}

void WebGLRenderingContext::drawArrays(GLenum mode, GLint first, GLsizei count) {
  glDrawArrays(mode, first, count);
}

void WebGLRenderingContext::drawElements(GLenum mode, GLsizei count, GLenum type, GLintptr offset) {
  glDrawElements(mode, count, type, (GLvoid *)&offset);
}

void WebGLRenderingContext::enable(GLenum cap) {
  glEnable(cap);
}

void WebGLRenderingContext::enableVertexAttribArray(GLuint index) {
  glEnableVertexAttribArray(index);
}

void WebGLRenderingContext::finish() {
  glFinish();
}


void WebGLRenderingContext::flush() {
  glFlush();
}


void WebGLRenderingContext::framebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, WebGLRenderbuffer *renderbuffer) {
  
}

void WebGLRenderingContext::framebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, WebGLTexture *texture, GLint level) {
  
}

void WebGLRenderingContext::frontFace(GLenum mode) {
  glFrontFace(mode);
}

void WebGLRenderingContext::generateMipmap(GLenum target) {
  
}

WebGLActiveInfo* WebGLRenderingContext::getActiveAttrib(WebGLProgram *program, GLuint index) {
  
}

WebGLActiveInfo* WebGLRenderingContext::getActiveUniform(WebGLProgram *program, GLuint index) {
  
}

WebGLShader** WebGLRenderingContext::getAttachedShaders(WebGLProgram *program) {
  
}

GLint WebGLRenderingContext::getAttribLocation(WebGLProgram *program, DOMString *name) {
  return glGetAttribLocation(program->id, name->value.c_str());
}

void* WebGLRenderingContext::getParameter(GLenum pname) {
  
}

void* WebGLRenderingContext::getBufferParameter(GLenum target, GLenum pname) {
  
}

GLenum WebGLRenderingContext::getError() {
  return glGetError();
}


void* WebGLRenderingContext::getFramebufferAttachmentParameter(GLenum target, GLenum attachment, GLenum pname) {
  
}

bool WebGLRenderingContext::getProgramParameter(WebGLProgram *program, GLenum pname) {
  return program->status(pname);
}

DOMString* WebGLRenderingContext::getProgramInfoLog(WebGLProgram *program) {
  
}

void* WebGLRenderingContext::getRenderbufferParameter(GLenum target, GLenum pname) {
  
}

void* WebGLRenderingContext::getShaderParameter(WebGLShader *shader, GLenum pname) {
  
}

DOMString* WebGLRenderingContext::getShaderInfoLog(WebGLShader *shader) {
  
}

DOMString* WebGLRenderingContext::getShaderSource(WebGLShader *shader) {
 
}

void* WebGLRenderingContext::getTexParameter(GLenum target, GLenum pname) {
  
}

void* WebGLRenderingContext::getUniform(WebGLProgram *program, WebGLUniformLocation *location) {
  
}

WebGLUniformLocation* WebGLRenderingContext::getUniformLocation(WebGLProgram *program, DOMString *name) {
  
}

void* WebGLRenderingContext::getVertexAttrib(GLuint index, GLenum pname) {
  
}

GLsizeiptr WebGLRenderingContext::getVertexAttribOffset(GLuint index, GLenum pname) {
  
}

void WebGLRenderingContext::hint(GLenum target, GLenum mode) {
  glHint(target, mode);
}

GLboolean WebGLRenderingContext::isBuffer(WebGLBuffer *buffer) {
  if (buffer) {
    return glIsBuffer(buffer->id);
  } else {
    return false;
  }
}

GLboolean WebGLRenderingContext::isEnabled(GLenum cap) {
  return glIsEnabled(cap);
}

GLboolean WebGLRenderingContext::isFramebuffer(WebGLFramebuffer *framebuffer) {
  if (framebuffer) {
    return true;
  } else {
    return false;
  }
}

GLboolean WebGLRenderingContext::isProgram(WebGLProgram *program) {
  if (program) {
    return glIsProgram(program->id);
  } else {
    return false;
  }
}

GLboolean WebGLRenderingContext::isRenderbuffer(WebGLRenderbuffer *renderbuffer) {
  if (renderbuffer) {
    return true;
  } else {
    return false;
  }
}

GLboolean WebGLRenderingContext::isShader(WebGLShader *shader) {
  if (shader) {
    return glIsShader(shader->id);
  } else {
    return false;
  }
}

GLboolean WebGLRenderingContext::isTexture(WebGLTexture *texture) {
  if (texture) {
    return glIsTexture(texture->id);
  } else {
    return false;
  }
}

void WebGLRenderingContext::lineWidth(GLfloat width) {
  glLineWidth(width);
}

void WebGLRenderingContext::linkProgram(WebGLProgram *program) {
  program->link();
}

void WebGLRenderingContext::pixelStorei(GLenum pname, GLint param) {
  glPixelStorei(pname, param);
}

void WebGLRenderingContext::polygonOffset(GLfloat factor, GLfloat units) {
  glPolygonOffset(factor, units);
}

void WebGLRenderingContext::readPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView *pixels) {
  glReadPixels(x, y, width, height, format, type, (GLvoid *)&pixels);
}

void WebGLRenderingContext::renderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
  
}

void WebGLRenderingContext::sampleCoverage(GLclampf value, GLboolean invert) {
  glSampleCoverage(value, invert);
}

void WebGLRenderingContext::scissor(GLint x, GLint y, GLsizei width, GLsizei height) {
  glScissor(x, y, width, height);
}

void WebGLRenderingContext::shaderSource(WebGLShader *shader, DOMString *source) {
  const char *cstring = source->value.c_str();
  glShaderSource(shader->id, 1, &cstring, NULL);
}

void WebGLRenderingContext::stencilFunc(GLenum func, GLint ref, GLuint mask) {
  glStencilFunc(func, ref, mask);
}

void WebGLRenderingContext::stencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
  glStencilFuncSeparate(face, func, ref, mask);
}

void WebGLRenderingContext::stencilMask(GLuint mask) {
  glStencilMask(mask);
}

void WebGLRenderingContext::stencilMaskSeparate(GLenum face, GLuint mask) {
  glStencilMaskSeparate(face, mask);
}

void WebGLRenderingContext::stencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
  glStencilOp(fail, zfail, zpass);
}

void WebGLRenderingContext::stencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass) {
  glStencilOpSeparate(face, fail, zfail, zpass);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, ArrayBufferView *pixels) {
  glTexImage2D(target, level, internalformat, width, height, border, format, type, (GLvoid *)&pixels);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, ImageData *pixels) {
  // glTexImage2D(target, level, internalformat, format, type, (GLvoid *)&pixels);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLImageElement *image) {
  // glTexImage2D(target, level, internalformat, format, type, (GLvoid *)&image);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLCanvasElement *canvas) {
  // glTexImage2D(target, level, internalformat, format, type, (GLvoid *)&canvas);
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLVideoElement *video) {
  // glTexImage2D(target, level, internalformat, format, type, (GLvoid *)&video);
}

void WebGLRenderingContext::texParameterf(GLenum target, GLenum pname, GLfloat param) {
  glTexParameterf(target, pname, param);
}

void WebGLRenderingContext::texParameteri(GLenum target, GLenum pname, GLint param) {
  glTexParameteri(target, pname, param);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView *pixels) {
  glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, (GLvoid *)&pixels);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, ImageData *pixels) {
  //glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, (GLvoid *)&pixels);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLImageElement *image) {
  //glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, (GLvoid *)&pixels);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLCanvasElement *canvas) {
  //glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, (GLvoid *)&pixels);
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLVideoElement *video) {
  //glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, (GLvoid *)&pixels);
}

void WebGLRenderingContext::uniform1f(WebGLUniformLocation *location, GLfloat x) {
  glUniform1f(location->id, x);
}

void WebGLRenderingContext::uniform1fv(WebGLUniformLocation *location, FloatArray *v) {
  glUniform1fv(location->id, v->length, (GLfloat *)&v);
}

void WebGLRenderingContext::uniform1fv(WebGLUniformLocation *location, float** v) {
  glUniform1fv(location->id, sizeof(v), (GLfloat *)&v);
}

void WebGLRenderingContext::uniform1i(WebGLUniformLocation *location, GLint x) {
  glUniform1i(location->id, x);
}

void WebGLRenderingContext::uniform1iv(WebGLUniformLocation *location, Int32Array *v) {
  glUniform1iv(location->id, v->length, (GLint *)&v);
}

void WebGLRenderingContext::uniform1iv(WebGLUniformLocation *location, long** v) {
  glUniform1iv(location->id, sizeof(v), (GLint *)&v);
}

void WebGLRenderingContext::uniform2f(WebGLUniformLocation *location, GLfloat x, GLfloat y) {
  glUniform2f(location->id, x, y);
}

void WebGLRenderingContext::uniform2fv(WebGLUniformLocation *location, FloatArray *v) {
  glUniform2fv(location->id, v->length, (GLfloat *)&v);
}

void WebGLRenderingContext::uniform2fv(WebGLUniformLocation *location, float** v) {
  glUniform2fv(location->id, sizeof(v), (GLfloat *)&v);
}

void WebGLRenderingContext::uniform2i(WebGLUniformLocation *location, GLint x, GLint y) {
  glUniform2i(location->id, x, y);
}

void WebGLRenderingContext::uniform2iv(WebGLUniformLocation *location, Int32Array *v) {
  glUniform2iv(location->id, v->length, (GLint *)&v);
}

void WebGLRenderingContext::uniform2iv(WebGLUniformLocation *location, long** v) {
  glUniform2iv(location->id, sizeof(v), (GLint *)&v);
}

void WebGLRenderingContext::uniform3f(WebGLUniformLocation *location, GLfloat x, GLfloat y, GLfloat z) {
  glUniform3f(location->id, x, y, z);
}

void WebGLRenderingContext::uniform3fv(WebGLUniformLocation *location, FloatArray *v) {
  glUniform3fv(location->id, v->length, (GLfloat *)&v);
}

void WebGLRenderingContext::uniform3fv(WebGLUniformLocation *location, float** v) {
  glUniform3fv(location->id, sizeof(v), (GLfloat *)&v);
}

void WebGLRenderingContext::uniform3i(WebGLUniformLocation *location, GLint x, GLint y, GLint z) {
  glUniform3i(location->id, x, y, z);
}

void WebGLRenderingContext::uniform3iv(WebGLUniformLocation *location, Int32Array *v) {
  glUniform3iv(location->id, v->length, (GLint *)&v);
}

void WebGLRenderingContext::uniform3iv(WebGLUniformLocation *location, long** v) {
  glUniform3iv(location->id, sizeof(v), (GLint *)&v);
}

void WebGLRenderingContext::uniform4f(WebGLUniformLocation *location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
  
}

void WebGLRenderingContext::uniform4fv(WebGLUniformLocation *location, FloatArray *v) {
  
}

void WebGLRenderingContext::uniform4fv(WebGLUniformLocation *location, float** v) {
  
}

void WebGLRenderingContext::uniform4i(WebGLUniformLocation *location, GLint x, GLint y, GLint z, GLint w) {
  
}

void WebGLRenderingContext::uniform4iv(WebGLUniformLocation *location, Int32Array *v) {
  
}

void WebGLRenderingContext::uniform4iv(WebGLUniformLocation *location, long** v) {
  
}

void WebGLRenderingContext::uniformMatrix2fv(WebGLUniformLocation *location, GLboolean transpose, FloatArray *value) {
  
}

void WebGLRenderingContext::uniformMatrix2fv(WebGLUniformLocation *location, GLboolean transpose, float** value) {
  
}

void WebGLRenderingContext::uniformMatrix3fv(WebGLUniformLocation *location, GLboolean transpose, FloatArray *value) {
  
}

void WebGLRenderingContext::uniformMatrix3fv(WebGLUniformLocation *location, GLboolean transpose, float** value) {
  
}

void WebGLRenderingContext::uniformMatrix4fv(WebGLUniformLocation *location, GLboolean transpose, FloatArray *value) {
  
}

void WebGLRenderingContext::uniformMatrix4fv(WebGLUniformLocation *location, GLboolean transpose, float** value) {
  
}

void WebGLRenderingContext::useProgram(WebGLProgram *program) {
  program->use();
}

void WebGLRenderingContext::validateProgram(WebGLProgram *program) {
  
}

void WebGLRenderingContext::vertexAttrib1f(GLuint indx, GLfloat x) {
  
}

void WebGLRenderingContext::vertexAttrib1fv(GLuint indx, FloatArray *values) {
  
}

void WebGLRenderingContext::vertexAttrib1fv(GLuint indx, float** values) {
  
}

void WebGLRenderingContext::vertexAttrib2f(GLuint indx, GLfloat x, GLfloat y) {
  
}

void WebGLRenderingContext::vertexAttrib2fv(GLuint indx, FloatArray *values) {
  
}

void WebGLRenderingContext::vertexAttrib2fv(GLuint indx, float** values) {
  
}

void WebGLRenderingContext::vertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z) {
  
}

void WebGLRenderingContext::vertexAttrib3fv(GLuint indx, FloatArray *values) {
  
}

void WebGLRenderingContext::vertexAttrib3fv(GLuint indx, float** values) {
  
}

void WebGLRenderingContext::vertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
  
}

void WebGLRenderingContext::vertexAttrib4fv(GLuint indx, FloatArray *values) {
  
}

void WebGLRenderingContext::vertexAttrib4fv(GLuint indx, float** values) {
  
}

void WebGLRenderingContext::vertexAttribPointer(GLuint indx,
                                                GLint size,
                                                GLenum type,
                                                GLboolean normalized,
                                                GLsizei stride,
                                                GLintptr offset)
{
  glVertexAttribPointer(indx, size, type, normalized, stride, (GLvoid *)&offset);
}

void WebGLRenderingContext::viewport(GLint x, GLint y, GLsizei width, GLsizei height) {
  glViewport(x, y, width, height);
}
