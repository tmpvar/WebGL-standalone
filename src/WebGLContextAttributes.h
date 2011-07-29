/**
  WebGL Standalone

  WebGLContextAttributes.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLContextAttributes_
#define _INCLUDED_WebGLContextAttributes_

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#ifdef _WIN32
  #include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif




class WebGLContextAttributes {
  public:
    WebGLContextAttributes();
    ~WebGLContextAttributes();

    bool alpha;
    bool depth;
    bool stencil;
    bool antialias;
    bool premultipliedAlpha;
};

#endif