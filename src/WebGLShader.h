/**
  WebGL Standalone

  WebGLShader.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLShader_
#define _INCLUDED_WebGLShader_

#include "arch/wrapper.h"

#include "WebGLObject.h"


class WebGLShader : WebGLObject {
  public:
    GLuint id;
    WebGLShader(GLenum type);
    ~WebGLShader();
    void compile();
  protected:
    bool compiled;
};

#endif