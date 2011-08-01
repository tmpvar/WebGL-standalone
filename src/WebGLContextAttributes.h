/**
  WebGL Standalone

  WebGLContextAttributes.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLContextAttributes_
#define _INCLUDED_WebGLContextAttributes_

#include "arch/wrapper.h"




class WebGLContextAttributes {
  public:
    bool alpha;
    bool depth;
    bool stencil;
    bool antialias;
    bool premultipliedAlpha;

    WebGLContextAttributes();
    ~WebGLContextAttributes();
};

#endif