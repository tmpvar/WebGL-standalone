/**
  WebGL Standalone

  WebGLObject.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLObject_
#define _INCLUDED_WebGLObject_

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




class WebGLObject {
  public:

    WebGLObject();
    ~WebGLObject();
};

#endif