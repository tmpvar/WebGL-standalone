var webgl = require('../lib/webgl.js');

var vertices = [
    0.75, 0.75, 0.0, 1,
    0.75, -0.75, 0.0, 1,
    -0.75, -0.75, 0.0, 1,
];

function e(name, result) {
  var e = ctx.getError()
  if (e) {
    console.log(name, 'failed!', e);
    fail();
  } else {
    console.log(name, 'passed! (', JSON.stringify(result), ')');
  }
  return result;
}

var ctx = new webgl.WebGLRenderingContext();
var program = e('create program', ctx.createProgram());
var shaders = {
  vertex : "attribute vec3 pos;\nvoid main() {\n  gl_Position = vec4(pos, 1.0);\n}",
  frag   : "void main() {\n  gl_FragColor = vec4(1.0, 0, 1, 1.0);\n}"
};

var vertexShader = e('create shader', ctx.createShader(ctx.VERTEX_SHADER));
var fragShader = e('create shader', ctx.createShader(ctx.FRAGMENT_SHADER));

e('shader source', ctx.shaderSource(vertexShader, shaders.vertex));
e('shader source', ctx.shaderSource(fragShader, shaders.frag));
e('compile shader', ctx.compileShader(vertexShader));
e('compile shader', ctx.compileShader(fragShader));
e('attach shader', ctx.attachShader(program, vertexShader));
e('attach shader', ctx.attachShader(program, fragShader));
e('link program', ctx.linkProgram(program));

if (!ctx.getProgramParameter(program, ctx.LINK_STATUS)) {
  console.log("Could not link program.\n Error:", ctx.getError());
  console.log(ctx.getProgramInfoLog(program));
  fail();
}

e('use program', ctx.useProgram(program));
var attr = e('attribute location', ctx.getAttribLocation(program, "pos"));
var vertexBuffer = e('create buffer', ctx.createBuffer());


e('bind buffer', ctx.bindBuffer(ctx.ARRAY_BUFFER, vertexBuffer));
e('buffer data', ctx.bufferData(ctx.ARRAY_BUFFER, new Float32Array(vertices), ctx.STATIC_DRAW));

e('viewport', ctx.viewport(0, 0, 300, 300));


var a = 10000;
while(a--) {
  e('clear color', ctx.clearColor(0.5, 0.5, 0.5, 1));
  e('clear', ctx.clear(ctx.COLOR_BUFFER_BIT | ctx.DEPTH_BUFFER_BIT));
  e('bind buffer', ctx.bindBuffer(ctx.ARRAY_BUFFER, vertexBuffer));
  e('enable vertex attrib array', ctx.enableVertexAttribArray(attr));
  e('vertex pointer', ctx.vertexAttribPointer(attr, 3, ctx.FLOAT, false, 0, 0));
  e('draw arrays', ctx.drawArrays(ctx.TRIANGLES, 0, 3));
  e('flush', ctx.flush());
}
console.log("DONE");