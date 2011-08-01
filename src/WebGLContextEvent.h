/**
  WebGL Standalone

  WebGLContextEvent.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLContextEvent_
#define _INCLUDED_WebGLContextEvent_

#include "arch/wrapper.h"

#include "Event.h"
#include "dom/DOMString.h"


class WebGLContextEvent : Event {
  public:
    DOMString getStatusMessage();
    void initWebGLContextEvent(DOMString *typeArg, bool canBubbleArg, bool cancelableArg, DOMString *statusMessageArg);

    WebGLContextEvent();
    ~WebGLContextEvent();
};

#endif