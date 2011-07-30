#include "../src/WebGLRenderingContext.h"
#include <iostream>
#include <assert.h>

void addShader(WebGLRenderingContext *gl, WebGLProgram *program, GLenum type, DOMString *source) {
  WebGLShader *shader = gl->createShader(type);
  gl->shaderSource(shader, source);
  gl->compileShader(shader);

  assert(gl->getShaderParameter(shader, gl->COMPILE_STATUS));

  gl->attachShader(program, shader);
}

int main() {
  WebGLRenderingContext *gl = new WebGLRenderingContext();

  WebGLProgram *program = gl->createProgram();

  DOMString *vertex_shader = new DOMString();
  /*
  "attribute vec3 pos;"+
  "void main() {"+
  "  gl_Position = vec4(pos, 2.0);"+
  "}"
  */
  
  DOMString *fragment_shader = new DOMString();
  /*"void main() {"+
  "  gl_FragColor = vec4(0.5, 0.5, 1.0, 1.0);"+
  "}"*/

  addShader(gl, program, gl->VERTEX_SHADER, vertex_shader);
  addShader(gl, program, gl->FRAGMENT_SHADER, fragment_shader);
  
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
    gl.useProgram(prog);

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
  
  std::cout << "Done!" << std::endl;
  return 0;
}