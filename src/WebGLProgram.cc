/**
  WebGL Standalone
  
  WebGLProgram.h
  
  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/

#include "WebGLProgram.h"

WebGLProgram::WebGLProgram() {
  this->id = glCreateProgram();
  this->linked = false;
}

WebGLProgram::~WebGLProgram() {
  glDeleteProgram(this->id);
}

void WebGLProgram::link() {
  glLinkProgram(this->id);

  GLint linked;
  glGetProgramiv(this->id, GL_LINK_STATUS, &linked);

  if (!linked) {
    this->linked = false;
  } else {
    this->linked = true;
  }
}

bool WebGLProgram::status(GLenum type) {
  switch (type) {
    case GL_LINK_STATUS:
      return this->linked;
    break;
  }
}

void WebGLProgram::attach(WebGLShader *shader) {
  glAttachShader(this->id, shader->id);
}

void WebGLProgram::use() {
  // TODO: toss an error here
  if (this->linked) {
    glUseProgram(this->id);
  }
}