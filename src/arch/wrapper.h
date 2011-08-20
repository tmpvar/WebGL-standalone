#ifndef _INCLIDE_ARCH_WRAPPER_
#define _INCLUDE_ARCH_WRAPPER_
  #include <iostream>
  #include <assert.h>
  using namespace std;

  #ifdef __APPLE__
    #include <GLUT/glut.h>
    #include <OpenGL/OpenGL.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <CoreFoundation/CoreFoundation.h>
    #include <ApplicationServices/ApplicationServices.h>
  #else
    #ifdef _WIN32
      #include <windows.h>
    #endif
      #include <GL/gl.h>
      #include <GL/glu.h>
      #include <GL/glut.h>
  #endif
#endif