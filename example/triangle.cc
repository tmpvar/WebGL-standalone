#include "../src/arch/wrapper.h"
#include "../src/WebGLRenderingContext.h"

#include <iostream>
#include <assert.h>
#include <unistd.h>

#include "../src/typedarray/ArrayBuffer.h"
#include "../src/util.h"
using namespace std;

WebGLRenderingContext *gl = NULL;
WebGLBuffer *buffer = NULL;
GLint attr;

void addShader(WebGLRenderingContext *gl, WebGLProgram *program, GLenum type, DOMString *source) {
  WebGLShader *shader = gl->createShader(type);

  gl->shaderSource(shader, source);
  gl->compileShader(shader);
  assert(gl->getShaderParameter(shader, WebGLRenderingContext::COMPILE_STATUS));

  gl->attachShader(program, shader);
}


void setup() {
  WebGLRenderingContext *gl = new WebGLRenderingContext();
  WebGLProgram *program = gl->createProgram();

  DOMString *pos = new DOMString();
  pos->value = "pos";

  DOMString *vertex_shader = new DOMString();
  vertex_shader->value = "attribute vec3 pos;\nvoid main() {\n  gl_Position = vec4(pos, 1.0);\n}";

  DOMString *fragment_shader = new DOMString();
  fragment_shader->value = "void main() {\n  gl_FragColor = vec4(1.0, 0, 1, 1.0);\n}";


  addShader(gl, program, WebGLRenderingContext::VERTEX_SHADER, vertex_shader);
  addShader(gl, program, WebGLRenderingContext::FRAGMENT_SHADER, fragment_shader);
  gl->linkProgram(program);

  assert(gl->getProgramParameter(program, gl->LINK_STATUS));

  gl->useProgram(program);


  Float32Array *array = new Float32Array(12);
  GLfloat tmp[9] = {
     0.0,  1.0, 0.0,
    -1.0, -1.0, 0.0,
     1.0, -1.0, 0.0,
  };
  buffer = gl->createBuffer();

  const float vertexPositions[] = {
    0.75f, 0.75f, 0.0f, 1.0f,
    0.75f, -0.75f, 0.0f, 1.0f,
    -0.75f, -0.75f, 0.0f, 1.0f,
  };

  // I'm not proud of this.
  memcpy(array->data, vertexPositions, array->size);

  gl->bindBuffer(WebGLRenderingContext::ARRAY_BUFFER, buffer);
  gl->bufferData(WebGLRenderingContext::ARRAY_BUFFER, array, WebGLRenderingContext::STATIC_DRAW);
  gl->bindBuffer(WebGLRenderingContext::ARRAY_BUFFER, buffer);

  glViewport(0, 0, 1920, 1200);
  gl->useProgram(program);
  attr = glGetAttribLocation(program->id, pos->value.c_str());
}

void render(void) {
  gl->clearColor(0.5, 0.5, 0.5, 1);
  gl->clear(WebGLRenderingContext::COLOR_BUFFER_BIT | WebGLRenderingContext::DEPTH_BUFFER_BIT);
  gl->bindBuffer(WebGLRenderingContext::ARRAY_BUFFER, buffer);
  gl->enableVertexAttribArray(attr);
  gl->vertexAttribPointer(attr, sizeof(GLfloat), GL_FLOAT, GL_FALSE, 0, 0);
  gl->drawArrays(GL_TRIANGLES, 0, 3);
  // TODO: implement these
  //glDisableVertexAttribArray(0);
  //glUseProgram(0);
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE);
  glutInitWindowSize (500, 500); // Set the width and height of the window
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("You’re first OpenGL Window");
  glutDisplayFunc(render);
  glutMainLoop();
  return 0;
}