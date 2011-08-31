#ifndef _INCLIDE_ARCH_WRAPPER_
#define _INCLUDE_ARCH_WRAPPER_
  #include <assert.h>


  #define BUFFER_OFFSET(i) ((char*)NULL + (i))

  #ifdef TARGET_OS_MAC
    #ifndef TARGET_OS_IPHONE
      #include "../../deps/glfw/include/GL/glfw.h"
      #include <OpenGL/OpenGL.h>
      #include <OpenGL/gl.h>
    #endif
  #else
    #include <iostream>
    using namespace std;

    #ifdef _WIN32
      #include <windows.h>
    #endif
      #include <GL/gl.h>
      #include <GL/glu.h>
      #include <GL/glut.h>
  #endif
#endif