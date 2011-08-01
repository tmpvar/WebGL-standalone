#include "../src/WebGLRenderingContext.h"
#include <iostream>
#include <assert.h>
#include <unistd.h>

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/graphics/IOGraphicsLib.h>
#include <Accelerate/Accelerate.h>
#include <ApplicationServices/ApplicationServices.h>

#include "../src/typedarray/ArrayBuffer.h"

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

void draw(WebGLRenderingContext *gl, WebGLProgram *program, ArrayBuffer *array) {
  gl->clearColor(0.8, 0.8, 0.8, 1);
  gl->clear(WebGLRenderingContext::COLOR_BUFFER_BIT);
  gl->bindBuffer(WebGLRenderingContext::ARRAY_BUFFER, gl->createBuffer());
  gl->bufferData(WebGLRenderingContext::ARRAY_BUFFER, array,WebGLRenderingContext::STATIC_DRAW);

  DOMString *pos = new DOMString();
  pos->value = "pos";

  GLint attr = gl->getAttribLocation(program, pos);
  gl->enableVertexAttribArray(attr);
  gl->vertexAttribPointer(attr, 3, WebGLRenderingContext::FLOAT, false, 0, 0);
  gl->drawArrays(WebGLRenderingContext::TRIANGLE_STRIP, 0, 4);
}

int main() {
  CGDirectDisplayID targetDisplay = getDisplay(0);
  CGOpenGLDisplayMask displayMask;
  CGLPixelFormatObj   pixelFormatObj;
  GLint               numPixelFormats;

  displayMask = CGDisplayIDToOpenGLDisplayMask(targetDisplay);

  CGLPixelFormatAttribute attribs[] = {
      kCGLPFAFullScreen,
      kCGLPFADisplayMask,
      (CGLPixelFormatAttribute)displayMask,
      (CGLPixelFormatAttribute)NULL
  };

  CGLContextObj context = NULL;

  CGLChoosePixelFormat(attribs, &pixelFormatObj, &numPixelFormats);
  CGLCreateContext(pixelFormatObj, NULL, &context);
  CGLDestroyPixelFormat(pixelFormatObj);
  CGLSetCurrentContext(context);
  CGLSetFullScreenOnDisplay(context, displayMask);

  WebGLRenderingContext *gl = new WebGLRenderingContext();
  WebGLProgram *program = gl->createProgram();

  DOMString *vertex_shader = new DOMString();
  vertex_shader->value = "attribute vec3 pos;\nvoid main() {\n  gl_Position = vec4(pos, 2.0);\n}";

  DOMString *fragment_shader = new DOMString();
  fragment_shader->value = "void main() {\n  gl_FragColor = vec4(0.5, 0.5, 1.0, 1.0);\n}";

  addShader(gl, program, WebGLRenderingContext::VERTEX_SHADER, vertex_shader);
  addShader(gl, program, WebGLRenderingContext::FRAGMENT_SHADER, fragment_shader);
  gl->linkProgram(program);

  assert(gl->getProgramParameter(program, gl->LINK_STATUS));

  gl->useProgram(program);

  ArrayBuffer *array = new ArrayBuffer();

/*  Float32Array *array new Float32Array({
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    1, 0, 0
  });*/

  // 5 frames for now
  int a = 5;
  while(a--) {
    draw(gl, program, array);
    usleep(1000000);
  }

  
  cout << "Done!" << endl;
  return 0;
}