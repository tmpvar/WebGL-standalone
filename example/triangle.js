var webgl = require('../lib/webgl.js');
var Image = webgl.DOMImage;

var vertices = [
   0.8,  0.8,  0.0, 1.0,
  -0.8,  0.8,  0.0, 1.0,
   0.8, -0.8,  0.0, 1.0,
  -0.8, -0.8,  0.0, 1.0
];

function e(name, result) {
  console.log(" ");
  var e = gl.getError()
  if (e) {
    console.log(name, 'failed!', e);
    fail();
  } else if (result === -1) {
    console.log(name, ' result code was -1');
    fail();
  } else {
    console.log(name, 'passed! (', JSON.stringify(result), ')');
  }
  return result;
}

var gl = new webgl.WebGLRenderingContext();
var program = e('create program', gl.createProgram());
var shaders = {
  frag   : readfile('../example/triangle.frag'),
  vertex : readfile('../example/triangle.vertex')
};

var vertexShader = e('create shader', gl.createShader(gl.VERTEX_SHADER));
var fragShader   = e('create shader', gl.createShader(gl.FRAGMENT_SHADER));

e('shader source',  gl.shaderSource(vertexShader, shaders.vertex));
e('shader source',  gl.shaderSource(fragShader, shaders.frag));
e('compile shader', gl.compileShader(vertexShader));
e('compile shader', gl.compileShader(fragShader));
e('attach shader',  gl.attachShader(program, vertexShader));
e('attach shader',  gl.attachShader(program, fragShader));
e('link program',   gl.linkProgram(program));
e('use program',    gl.useProgram(program));

var attr = e('attribute location', gl.getAttribLocation(program, "aVertexPosition"));
var textureAttr = e('texture location', gl.getAttribLocation(program, "aTextureCoord"));
var samplerUniform = e('get uSampler uniform', gl.getUniformLocation(program, "sampler"));
e('uniformi', gl.uniform1i(samplerUniform, 0));


// Setup texture
var img = new Image();
var textureImage;
img.onload = function() {
  textureImage = e('create texture', gl.createTexture());

  e('bind texture', gl.bindTexture(gl.TEXTURE_2D, textureImage));

  e('tex image 2d', gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, img));

  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
  gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
};

// TODO: this will not always be sync!
img.src = "../example/evil_monkey_9.tga";

var squareTextureBuffer = e('create texture buffer', gl.createBuffer());
e('bind texture buffer', gl.bindBuffer(gl.ARRAY_BUFFER, squareTextureBuffer));

e('buffer texture coords', gl.bufferData(gl.ARRAY_BUFFER, new Float32Array([
  1.0,  1.0,
  0.0,  1.0,
  1.0,  0.0,
  0.0,  0.0
]), gl.STATIC_DRAW));

if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
  console.log("Could not link program.\n Error:", gl.getError());
  console.log(gl.getProgramInfoLog(program));
  fail();
}


var vertexBuffer = e('create buffer', gl.createBuffer());

e('bind buffer',                 gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer));
e('buffer data',                 gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW));
e('viewport',                    gl.viewport(0, 0, 300, 300));
e('enable vertex attrib array',  gl.enableVertexAttribArray(attr));
e('enable texture attrib array', gl.enableVertexAttribArray(textureAttr));
e('bind buffer',                 gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer));
e('vertex pointer',              gl.vertexAttribPointer(attr, 4, gl.FLOAT, false, 0, 0));
e('bind texture buffer',         gl.bindBuffer(gl.ARRAY_BUFFER, squareTextureBuffer));
e('vertex point texture',        gl.vertexAttribPointer(textureAttr, 2, gl.FLOAT, false, 0, 0));
e('enable depth test',           gl.enable(gl.DEPTH_TEST));



var a = 50000;
while(a--) {

  e('bind texture',                gl.bindTexture(gl.TEXTURE_2D, textureImage));

  e('clear color',  gl.clearColor(0.5, 0.5, 0.5, 1));
  e('clear',        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT));
  e('draw arrays',  gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4));
  e('flush',        gl.flush());
}
