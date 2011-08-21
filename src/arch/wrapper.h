#ifndef _INCLIDE_ARCH_WRAPPER_
#define _INCLUDE_ARCH_WRAPPER_
  #include <iostream>
  #include <assert.h>
  using namespace std;

  #ifdef __APPLE__
    #include "../../deps/glfw/include/GL/glfw.h"
    #include <OpenGL/OpenGL.h>
    #include <OpenGL/gl.h>
  #else
    #ifdef _WIN32
      #include <windows.h>
    #endif
      #include <GL/gl.h>
      #include <GL/glu.h>
      #include <GL/glut.h>
  #endif
#endif