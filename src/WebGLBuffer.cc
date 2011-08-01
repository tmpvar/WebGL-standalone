/**
  WebGL Standalone
  
  WebGLBuffer.h
  
  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/

#include "WebGLBuffer.h"

WebGLBuffer::WebGLBuffer() {
  glGenBuffers(1, &this->id);
}

WebGLBuffer::~WebGLBuffer() {
  
}

