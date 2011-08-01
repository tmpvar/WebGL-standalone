/**
  WebGL Standalone
  
  WebGLShader.h
  
  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/

#include "WebGLShader.h"

WebGLShader::WebGLShader(GLenum type) {
  this->id = glCreateShader(type);
}

WebGLShader::~WebGLShader() {
  
}

void WebGLShader::compile() {
  glCompileShader(this->id);

  GLint compiled;

  glGetShaderiv(this->id, GL_COMPILE_STATUS, &compiled );

  if (!compiled) {
    GLint  length;
    GLchar *log;
    glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &length );

    log = (GLchar*) malloc(length);
    glGetShaderInfoLog(this->id, length, &length, log);
    cerr << log << endl;
    free(log);
    
    this->compiled = false;
  } else {
    this->compiled = true;
  }
}
