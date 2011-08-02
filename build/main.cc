#include "../src/WebGLRenderingContext.h"
#include <iostream>
#include <assert.h>
#include <unistd.h>

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

void draw(WebGLRenderingContext *gl, WebGLProgram *program, Float32Array *array, DOMString *pos) {
  gl->bindBuffer(WebGLRenderingContext::ARRAY_BUFFER, gl->createBuffer());
  cout << "bind buffer: " << gluErrorString(glGetError()) << endl;
  
  gl->bufferData(WebGLRenderingContext::ARRAY_BUFFER, array, WebGLRenderingContext::STATIC_DRAW);
  cout << "buffer data: " << gluErrorString(glGetError()) << endl;

  GLint attr = gl->getAttribLocation(program, pos);
  cout << "attrib location" << attr << " ERROR: " << gluErrorString(glGetError()) << endl;
  gl->enableVertexAttribArray(attr);
  cout << "enable vertex attribute array: " << gluErrorString(glGetError()) << endl;

  gl->vertexAttribPointer(attr, sizeof(GLfloat), WebGLRenderingContext::FLOAT, false, 0, 0);
  
  cout << "vertex attribute pointer: " << gluErrorString(glGetError()) << endl;

  gl->drawArrays(WebGLRenderingContext::TRIANGLES, 0, 3);
  cout << "draw arrays: " << gluErrorString(glGetError()) << endl;

}

int main() {
  CGDirectDisplayID targetDisplay = getDisplay(0);
  CGOpenGLDisplayMask displayMask;
  CGLPixelFormatObj   pixelFormatObj;
  GLint               numPixelFormats;

  displayMask = CGDisplayIDToOpenGLDisplayMask(targetDisplay);

  CGLPixelFormatAttribute attribs[] = {
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
  vertex_shader->value = "attribute vec3 pos;\nvoid main() {\n  gl_Position = vec4(pos, 2.0);\n}";

  DOMString *fragment_shader = new DOMString();
  fragment_shader->value = "void main() {\n  gl_FragColor = vec4(1.0, 0, 1, 1.0);\n}";


  addShader(gl, program, WebGLRenderingContext::VERTEX_SHADER, vertex_shader);
  addShader(gl, program, WebGLRenderingContext::FRAGMENT_SHADER, fragment_shader);
  gl->linkProgram(program);

  assert(gl->getProgramParameter(program, gl->LINK_STATUS));

  gl->useProgram(program);

  Float32Array *array = new Float32Array(9);
  GLfloat tmp[9] = {
    0, 1, 0,
    -1, -1, 0,
    1, -1, 0,
  };
  
  // I'm not proud of this.
  memcpy(tmp, array->data, array->size);
  
  gl->enable(WebGLRenderingContext::DEPTH_TEST);
  // 5 frames for now
  int a = 500;
  int interval = 1;
  while(a--) {
    gl->viewport(0, 0, 1600, 1200);

    gl->clearColor(0.5, 0.5, 0.5, 1);
    cout << "clear color: " << gluErrorString(glGetError()) << endl;

    gl->clear(WebGLRenderingContext::COLOR_BUFFER_BIT | WebGLRenderingContext::DEPTH_BUFFER_BIT);
    cout << "clear: " << gluErrorString(glGetError()) << endl;
    
    gluPerspective(45, 1600 / 1200, 0.1, 100.0);
    glLoadIdentity();
    glTranslatef(-1.5, 0.0, -7.0);
    draw(gl, program, array, pos);
    CGLSetParameter( context, kCGLCPSwapInterval, &interval );
    CGLFlushDrawable( context );
  }

  CGLReleaseContext(context);
  cout << "Done!" << endl;
  return 0;
}