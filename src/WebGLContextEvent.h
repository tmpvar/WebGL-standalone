/**
  WebGL Standalone

  WebGLContextEvent.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLContextEvent_
#define _INCLUDED_WebGLContextEvent_

#include <gl/gl.h>
#include "Event .h"


class WebGLContextEvent : Event  {
  public:
    WebGLContextEvent();
    ~WebGLContextEvent();

    readonly attribute DOMString statusMessage;
    void initWebGLContextEvent(DOMString typeArg, boolean canBubbleArg, boolean cancelableArg, DOMString statusMessageArg);
};

#endif