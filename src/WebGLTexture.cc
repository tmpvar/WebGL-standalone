/**
  WebGL Standalone
  
  WebGLTexture.h
  
  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/

#include "WebGLTexture.h"

WebGLTexture::WebGLTexture() {
  glGenTextures(1, &this->texture);
}

WebGLTexture::~WebGLTexture() {
  
}

void WebGLTexture::bind(GLenum type) {
  glBindTexture(type, this->texture);
}

