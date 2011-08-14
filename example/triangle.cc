#include "../src/arch/wrapper.h"
#include "../src/WebGLRenderingContext.h"

#include <iostream>
#include <assert.h>
#include <unistd.h>

#include "../src/typedarray/ArrayBuffer.h"
#include "../src/util.h"
using namespace std;

void addShader(WebGLRenderingContext *gl, WebGLProgram *program, GLenum type, DOMString *source) {
  WebGLShader *shader = gl->createShader(type);

  gl->shaderSource(shader, source);
  gl->compileShader(shader);
  assert(gl->getShaderParameter(shader, WebGLRenderingContext::COMPILE_STATUS));

  gl->attachShader(program, shader);
}

CGDirectDisplayID getDisplay(unsigned int index) {
  CGDisplayErr      dErr;
  CGDisplayCount    displayCount;
  CGDisplayCount    maxDisplays = 8;
  CGDirectDisplayID onlineDisplays[8];

  dErr = CGGetOnlineDisplayList(maxDisplays, onlineDisplays, &displayCount);

  if (dErr != kCGErrorSuccess) {
      displayCount = 0;
  }

  if ((index < 0) || (index > (displayCount - 1))) {
      return 0;
  }

  return onlineDisplays[index];
}


int main() {
  CGDirectDisplayID targetDisplay = getDisplay(0);
  CGOpenGLDisplayMask displayMask;
  CGLPixelFormatObj   pixelFormatObj;
  GLint               numPixelFormats;

  displayMask = CGDisplayIDToOpenGLDisplayMask(targetDisplay);

  CGLPixelFormatAttribute attribs[] = {
      kCGLPFAAccelerated,
      kCGLPFANoRecovery,
      kCGLPFADoubleBuffer,
      kCGLPFAFullScreen,
      kCGLPFAStencilSize, ( CGLPixelFormatAttribute ) 8,
      kCGLPFADisplayMask,
      (CGLPixelFormatAttribute)CGDisplayIDToOpenGLDisplayMask( kCGDirectMainDisplay ),
      (CGLPixelFormatAttribute)NULL
  };

  CGLContextObj context = NULL;

  CGLChoosePixelFormat(attribs, &pixelFormatObj, &numPixelFormats);
  CGLCreateContext(pixelFormatObj, NULL, &context);
  CGLDestroyPixelFormat(pixelFormatObj);
  CGLSetCurrentContext(context);
  CGLRetainContext(context);
  CGLSetFullScreenOnDisplay(context, displayMask);

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



  // 5 frames for now
  int a = 100;
  int interval = 1;
  WebGLBuffer *buffer = gl->createBuffer();

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
  GLint attr = glGetAttribLocation(program->id, pos->value.c_str());

  while(a--) {
    gl->clearColor(0.5, 0.5, 0.5, 1);
    gl->clear(WebGLRenderingContext::COLOR_BUFFER_BIT | WebGLRenderingContext::DEPTH_BUFFER_BIT);
    gl->bindBuffer(WebGLRenderingContext::ARRAY_BUFFER, buffer);
    gl->enableVertexAttribArray(attr);
    gl->vertexAttribPointer(attr, sizeof(GLfloat), GL_FLOAT, GL_FALSE, 0, 0);
    gl->drawArrays(GL_TRIANGLES, 0, 3);

    // TODO: implement these
    //glDisableVertexAttribArray(0);
    //glUseProgram(0);

    CGLSetParameter( context, kCGLCPSwapInterval, &interval );
    CGLFlushDrawable( context );
  }

  CGLReleaseContext(context);
  cout << "Done!" << endl;
  return 0;
}