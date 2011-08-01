/**
  WebGL Standalone
  
  FloatArray.h
  
  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/

#include "FloatArray.h"

FloatArray::FloatArray() {
  
}

FloatArray::~FloatArray() {
  
}


Float32Array::Float32Array(unsigned int length) {
  this->length = length;
  this->size   = (unsigned int)sizeof(GLfloat) * length;
  this->data = (GLfloat *)malloc(size);
}

Float32Array::~Float32Array() {
  free(this->data);
}
