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
  
}

void WebGLRenderingContext::bindBuffer(GLenum target, WebGLBuffer *buffer) {
  
}

void WebGLRenderingContext::bindFramebuffer(GLenum target, WebGLFramebuffer *framebuffer) {
  
}

void WebGLRenderingContext::bindRenderbuffer(GLenum target, WebGLRenderbuffer *renderbuffer) {
  
}

void WebGLRenderingContext::bindTexture(GLenum target, WebGLTexture *texture) {
  
}

void WebGLRenderingContext::blendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
  
}

void WebGLRenderingContext::blendEquation(GLenum mode) {
  
}

void WebGLRenderingContext::blendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
  
}

void WebGLRenderingContext::blendFunc(GLenum sfactor, GLenum dfactor) {
  
}

void WebGLRenderingContext::blendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
  
}

void WebGLRenderingContext::bufferData(GLenum target, GLsizeiptr size, GLenum usage) {
  
}

void WebGLRenderingContext::bufferData(GLenum target, ArrayBufferView *data, GLenum usage) {
  
}

void WebGLRenderingContext::bufferData(GLenum target, ArrayBuffer *data, GLenum usage) {
  
}

void WebGLRenderingContext::bufferSubData(GLenum target, GLintptr offset, ArrayBufferView *data) {
  
}

void WebGLRenderingContext::bufferSubData(GLenum target, GLintptr offset, ArrayBuffer *data) {
  
}

GLenum WebGLRenderingContext::checkFramebufferStatus(GLenum target) {
  
}

void WebGLRenderingContext::clear(GLbitfield mask) {
  
}

void WebGLRenderingContext::clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
  
}

void WebGLRenderingContext::clearDepth(GLclampf depth) {
  
}

void WebGLRenderingContext::clearStencil(GLint s) {
  
}

void WebGLRenderingContext::colorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
  
}

void WebGLRenderingContext::compileShader(WebGLShader *shader) {
  shader->compile();
}

void WebGLRenderingContext::copyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
  
}

void WebGLRenderingContext::copyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
  
}

WebGLBuffer* WebGLRenderingContext::createBuffer() {
  
}


WebGLFramebuffer* WebGLRenderingContext::createFramebuffer() {
  
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
  
}

void WebGLRenderingContext::depthMask(GLboolean flag) {
  
}

void WebGLRenderingContext::depthRange(GLclampf zNear, GLclampf zFar) {
  
}

void WebGLRenderingContext::detachShader(WebGLProgram *program, WebGLShader *shader) {
  
}

void WebGLRenderingContext::disable(GLenum cap) {
  
}

void WebGLRenderingContext::disableVertexAttribArray(GLuint index) {
  
}

void WebGLRenderingContext::drawArrays(GLenum mode, GLint first, GLsizei count) {
  
}

void WebGLRenderingContext::drawElements(GLenum mode, GLsizei count, GLenum type, GLintptr offset) {
  
}

void WebGLRenderingContext::enable(GLenum cap) {
  
}

void WebGLRenderingContext::enableVertexAttribArray(GLuint index) {
  
}

void WebGLRenderingContext::finish() {
  
}


void WebGLRenderingContext::flush() {
  
}


void WebGLRenderingContext::framebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, WebGLRenderbuffer *renderbuffer) {
  
}

void WebGLRenderingContext::framebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, WebGLTexture *texture, GLint level) {
  
}

void WebGLRenderingContext::frontFace(GLenum mode) {
  
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
  
}

void* WebGLRenderingContext::getParameter(GLenum pname) {
  
}

void* WebGLRenderingContext::getBufferParameter(GLenum target, GLenum pname) {
  
}

GLenum WebGLRenderingContext::getError() {
  
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
  
}

GLboolean WebGLRenderingContext::isBuffer(WebGLBuffer *buffer) {
  
}

GLboolean WebGLRenderingContext::isEnabled(GLenum cap) {
  
}

GLboolean WebGLRenderingContext::isFramebuffer(WebGLFramebuffer *framebuffer) {
  
}

GLboolean WebGLRenderingContext::isProgram(WebGLProgram *program) {
  
}

GLboolean WebGLRenderingContext::isRenderbuffer(WebGLRenderbuffer *renderbuffer) {
  
}

GLboolean WebGLRenderingContext::isShader(WebGLShader *shader) {
  
}

GLboolean WebGLRenderingContext::isTexture(WebGLTexture *texture) {
  
}

void WebGLRenderingContext::lineWidth(GLfloat width) {
  
}

void WebGLRenderingContext::linkProgram(WebGLProgram *program) {
  program->link();
}

void WebGLRenderingContext::pixelStorei(GLenum pname, GLint param) {
  
}

void WebGLRenderingContext::polygonOffset(GLfloat factor, GLfloat units) {
  
}

void WebGLRenderingContext::readPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView *pixels) {
  
}

void WebGLRenderingContext::renderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
  
}

void WebGLRenderingContext::sampleCoverage(GLclampf value, GLboolean invert) {
  
}

void WebGLRenderingContext::scissor(GLint x, GLint y, GLsizei width, GLsizei height) {
  
}

void WebGLRenderingContext::shaderSource(WebGLShader *shader, DOMString *source) {
  const char *cstring = source->value.c_str();
  glShaderSource(shader->id, 1, &cstring, NULL);
}

void WebGLRenderingContext::stencilFunc(GLenum func, GLint ref, GLuint mask) {
  
}

void WebGLRenderingContext::stencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
  
}

void WebGLRenderingContext::stencilMask(GLuint mask) {
  
}

void WebGLRenderingContext::stencilMaskSeparate(GLenum face, GLuint mask) {
  
}

void WebGLRenderingContext::stencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
  
}

void WebGLRenderingContext::stencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass) {
  
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, ArrayBufferView *pixels) {
  
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, ImageData *pixels) {
  
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLImageElement *image) {
  
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLCanvasElement *canvas) {
  
}

void WebGLRenderingContext::texImage2D(GLenum target, GLint level, GLenum internalformat, GLenum format, GLenum type, HTMLVideoElement *video) {
  
}

void WebGLRenderingContext::texParameterf(GLenum target, GLenum pname, GLfloat param) {
  
}

void WebGLRenderingContext::texParameteri(GLenum target, GLenum pname, GLint param) {
  
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, ArrayBufferView *pixels) {
  
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, ImageData *pixels) {
  
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLImageElement *image) {
  
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLCanvasElement *canvas) {
  
}

void WebGLRenderingContext::texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLenum format, GLenum type, HTMLVideoElement *video) {
  
}

void WebGLRenderingContext::uniform1f(WebGLUniformLocation *location, GLfloat x) {
  
}

void WebGLRenderingContext::uniform1fv(WebGLUniformLocation *location, FloatArray *v) {
  
}

void WebGLRenderingContext::uniform1fv(WebGLUniformLocation *location, float** v) {
  
}

void WebGLRenderingContext::uniform1i(WebGLUniformLocation *location, GLint x) {
  
}

void WebGLRenderingContext::uniform1iv(WebGLUniformLocation *location, Int32Array *v) {
  
}

void WebGLRenderingContext::uniform1iv(WebGLUniformLocation *location, long** v) {
  
}

void WebGLRenderingContext::uniform2f(WebGLUniformLocation *location, GLfloat x, GLfloat y) {
  
}

void WebGLRenderingContext::uniform2fv(WebGLUniformLocation *location, FloatArray *v) {
  
}

void WebGLRenderingContext::uniform2fv(WebGLUniformLocation *location, float** v) {
  
}

void WebGLRenderingContext::uniform2i(WebGLUniformLocation *location, GLint x, GLint y) {
  
}

void WebGLRenderingContext::uniform2iv(WebGLUniformLocation *location, Int32Array *v) {
  
}

void WebGLRenderingContext::uniform2iv(WebGLUniformLocation *location, long** v) {
  
}

void WebGLRenderingContext::uniform3f(WebGLUniformLocation *location, GLfloat x, GLfloat y, GLfloat z) {
  
}

void WebGLRenderingContext::uniform3fv(WebGLUniformLocation *location, FloatArray *v) {
  
}

void WebGLRenderingContext::uniform3fv(WebGLUniformLocation *location, float** v) {
  
}

void WebGLRenderingContext::uniform3i(WebGLUniformLocation *location, GLint x, GLint y, GLint z) {
  
}

void WebGLRenderingContext::uniform3iv(WebGLUniformLocation *location, Int32Array *v) {
  
}

void WebGLRenderingContext::uniform3iv(WebGLUniformLocation *location, long** v) {
  
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

void WebGLRenderingContext::vertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) {
  
}

void WebGLRenderingContext::viewport(GLint x, GLint y, GLsizei width, GLsizei height) {
  
}

