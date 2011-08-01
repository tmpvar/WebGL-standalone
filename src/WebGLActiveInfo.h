/**
  WebGL Standalone

  WebGLActiveInfo.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLActiveInfo_
#define _INCLUDED_WebGLActiveInfo_

#include "arch/wrapper.h"

#include "dom/DOMString.h"


class WebGLActiveInfo {
  public:
    GLint getSize();
    GLenum getType();
    DOMString getName();

    WebGLActiveInfo();
    ~WebGLActiveInfo();
};

#endif