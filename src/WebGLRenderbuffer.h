/**
  WebGL Standalone

  WebGLRenderbuffer.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLRenderbuffer_
#define _INCLUDED_WebGLRenderbuffer_

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

#include "WebGLObject.h"


class WebGLRenderbuffer : WebGLObject {
  public:
    WebGLRenderbuffer();
    ~WebGLRenderbuffer();

};

#endif