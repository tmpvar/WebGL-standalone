/**
  WebGL Standalone

  FloatArray.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_FloatArray_
#define _INCLUDED_FloatArray_

#include "../arch/wrapper.h"
#include "ArrayBuffer.h"



class FloatArray {
  public:
    GLuint length;
    FloatArray();
    ~FloatArray();
};

class Float32Array : public ArrayBuffer {
  public:
    Float32Array(unsigned int length);
    ~Float32Array();
};



#endif