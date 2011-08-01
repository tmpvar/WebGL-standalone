/**
  WebGL Standalone

  WebGLTexture.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLTexture_
#define _INCLUDED_WebGLTexture_

#include "arch/wrapper.h"

#include "WebGLObject.h"


class WebGLTexture : WebGLObject {
  public:
    GLuint id;
    WebGLTexture();
    ~WebGLTexture();
};

#endif