/**
  WebGL Standalone

  WebGLBuffer.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLBuffer_
#define _INCLUDED_WebGLBuffer_

#include "arch/wrapper.h"

#include "WebGLObject.h"


class WebGLBuffer : WebGLObject {
  public:
    GLuint id;
    WebGLBuffer();
    ~WebGLBuffer();
};

#endif