var WebGLRenderingContext = require('lib/webgl.js');

var ctx = new WebGLRenderingContext();
var program = ctx.createProgram();
var shaders = {
  vertex : "attribute vec3 pos;\nvoid main() {\n  gl_Position = vec4(pos, 1.0);\n}",
  frag   : "void main() {\n  gl_FragColor = vec4(1.0, 0, 1, 1.0);\n}"
};

var vertexShader = ctx.createShader(ctx.VERTEX_SHADER);
var fragShader = ctx.createShader(ctx.FRAGMENT_SHADER);

ctx.shaderSource(vertexShader, shaders.vertex);
ctx.shaderSource(fragShader, shaders.frag);

ctx.compileShader(vertexShader);
ctx.compileShader(fragShader);

ctx.attachShader(program, vertexShader);
ctx.attachShader(program, fragShader);
ctx.linkProgram(program);

if (!ctx.getProgramParameter(program, ctx.LINK_STATUS)) {
  console.log("Could not link program");
  fail();
}

ctx.useProgram(program);
var attr = ctx.getAttribLocation(program, "pos");
var vertexBuffer = ctx.createBuffer();

vertexBuffer.itemSize = 3;
vertexBuffer.numItems = 3;

/*
  const float vertexPositions[] = {
    0.75f, 0.75f, 0.0f, 1.0f,
    0.75f, -0.75f, 0.0f, 1.0f,
    -0.75f, -0.75f, 0.0f, 1.0f,
  };
*/

var vertices = [
   0.0,  1.0,  0.0,
  -1.0, -1.0,  0.0,
   1.0, -1.0,  0.0
];

ctx.bindBuffer(ctx.ARRAY_BUFFER, vertexBuffer);
ctx.bufferData(ctx.ARRAY_BUFFER, new Float32Array(vertexBuffer));


while(1) {
  ctx.clearColor(0.5, 0.5, 0.5, 1);
  ctx.clear(ctx.COLOR_BUFFER_BIT, ctx.DEPTH_BUFFER_BIT);
  ctx.bindBuffer(ctx.ARRAY_BUFFER, vertexBuffer);
  ctx.enableVertexAttribArray(attr);
  ctx.vertexAttribPointer(attr, vertexBuffer.itemSize, ctx.FLOAT, false, 0, 0);
  ctx.drawArrays(ctx.TRIANGLES, 0, 3);
  ctx.flush();
}