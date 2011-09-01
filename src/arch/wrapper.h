#ifndef _INCLIDE_ARCH_WRAPPER_
#define _INCLUDE_ARCH_WRAPPER_
  #include <assert.h>


  #define BUFFER_OFFSET(i) ((char*)NULL + (i))

  #ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
    #define TARGET_MOBILE 1
    #include <OpenGLES/ES1/gl.h>
    #include <OpenGLES/ES1/glext.h>
    #include <OpenGLES/ES2/gl.h>
    #include <OpenGLES/ES2/glext.h>
    typedef double GLclampd;
  #else
    #define TARGET_DESKTOP 1
    #ifdef __APPLE__
      #include "../../deps/glfw/include/GL/glfw.h"
      #include <iostream>
      #include <OpenGL/OpenGL.h>
      #include <OpenGL/gl.h>
      using namespace std;
    #else
      #include <iostream>
      using namespace std;
      #ifdef _WIN32
        #include <windows.h>
      #else
        #include <GL/gl.h>
        #include <GL/glu.h>
        #include <GL/glut.h>
      #endif
    #endif
  #endif
#endif