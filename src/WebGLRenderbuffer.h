/**
  WebGL Standalone

  WebGLRenderbuffer.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLRenderbuffer_
#define _INCLUDED_WebGLRenderbuffer_

#include "arch/wrapper.h"

#include "WebGLObject.h"


class WebGLRenderbuffer : WebGLObject {
  public:
    GLuint id;
    WebGLRenderbuffer();
    ~WebGLRenderbuffer();
};

#endif