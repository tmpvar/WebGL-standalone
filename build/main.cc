#include "../src/WebGLRenderingContext.h"
#include <iostream>
#include <assert.h>

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/graphics/IOGraphicsLib.h>
#include <Accelerate/Accelerate.h>
#include <ApplicationServices/ApplicationServices.h>

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

/*
  function attributeSetFloats(gl, prog, attr_name, rsize, arr) {
    gl.bindBuffer(gl.ARRAY_BUFFER, gl.createBuffer());
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(arr),
      gl.STATIC_DRAW);
    var attr = gl.getAttribLocation(prog, attr_name);
    gl.enableVertexAttribArray(attr);
    gl.vertexAttribPointer(attr, rsize, gl.FLOAT, false, 0, 0);
  }

  function draw() {
    try {
      var gl = document.getElementById("webgl")
        .getContext("experimental-webgl");
      if (!gl) { throw "x"; }
    } catch (err) {
      throw "Your web browser does not support WebGL!";
    }
    gl.clearColor(0.8, 0.8, 0.8, 1);
    gl.clear(gl.COLOR_BUFFER_BIT);

    var prog = shaderProgram(gl,
      "attribute vec3 pos;"+
      "void main() {"+
      "  gl_Position = vec4(pos, 2.0);"+
      "}",
      "void main() {"+
      "  gl_FragColor = vec4(0.5, 0.5, 1.0, 1.0);"+
      "}"
    );
    */
    gl->useProgram(program);
/*
    attributeSetFloats(gl, prog, "pos", 3, [
      -1, 0, 0,
      0, 1, 0,
      0, -1, 0,
      1, 0, 0
    ]);

    gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);
  }

  function init() {
    try {
      draw();
    } catch (e) {
      alert("Error: "+e);
    }
  }
  setTimeout(init, 100);*/
  
  cout << "Done!" << endl;
  return 0;
}