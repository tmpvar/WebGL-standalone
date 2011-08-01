/**
  WebGL Standalone

  WebGLProgram.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLProgram_
#define _INCLUDED_WebGLProgram_

#include "arch/wrapper.h"

#include "WebGLObject.h"
#include "WebGLShader.h"


class WebGLProgram : WebGLObject {
  public:
    GLuint id;
    WebGLProgram();
    ~WebGLProgram();
    
    void link();
    bool status(GLenum type);
    void use();
    void attach(WebGLShader *shader);
  protected:
    bool linked;
};

#endif