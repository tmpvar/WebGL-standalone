/**
  WebGL Standalone

  WebGLContextEvent.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLContextEvent_
#define _INCLUDED_WebGLContextEvent_

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

#include "Event.h"
#include "DOMString.h"


class WebGLContextEvent : Event {
  public:
    WebGLContextEvent();
    ~WebGLContextEvent();

DOMString getStatusMessage();
    void initWebGLContextEvent(DOMString typeArg, bool canBubbleArg, bool cancelableArg, DOMString statusMessageArg);
};

#endif