/**
  WebGL Standalone

  WebGLContextAttributes .h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLContextAttributes _
#define _INCLUDED_WebGLContextAttributes _

#include <gl/gl.h>



class WebGLContextAttributes  {
  public:
    WebGLContextAttributes ();
    ~WebGLContextAttributes ();

    attribute boolean alpha;
    attribute boolean depth;
    attribute boolean stencil;
    attribute boolean antialias;
    attribute boolean premultipliedAlpha;
};

#endif