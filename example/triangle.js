var webgl = require('../lib/webgl.js');
var Image = webgl.DOMImage;

var vertices = [
   0.8,  0.8,  0.0,
  -0.8,  0.8,  0.0,
   0.8, -0.8,  0.0,
  -0.8, -0.8,  0.0
];

var textureCoords = [
    0.0,  0.0,
    1.0,  0.0,
    1.0,  1.0,
    0.0,  1.0,
];


function e(name, result) {
  var e = gl.getError()
  if (e) {
    console.log(name, 'failed!', e);
    fail();
  } else {
    console.log(name, 'passed! (', JSON.stringify(result), ')');
  }
  return result;
}

var gl = new webgl.WebGLRenderingContext();
var program = e('create program', gl.createProgram());
var shaders = {
  frag : "#ifdef GL_ES\nprecision highp float;\n#endif\n\nvarying vec2 vTextureCoord;\n\nuniform sampler2D uSampler;\n\nvoid main(void) {\n gl_FragColor = texture2D(uSampler, vec2(0, 0));\n}",
  vertex   : "attribute vec3 aVertexPosition;\nattribute vec2 aTextureCoord;varying vec2 vTextureCoord;\n\n\nvoid main(void) {\n    gl_Position = vec4(aVertexPosition, 1.0);\n    vTextureCoord = aTextureCoord;\n}"
};

var vertexShader = e('create shader', gl.createShader(gl.VERTEX_SHADER));
var fragShader = e('create shader', gl.createShader(gl.FRAGMENT_SHADER));

e('shader source', gl.shaderSource(vertexShader, shaders.vertex));
e('shader source', gl.shaderSource(fragShader, shaders.frag));
e('compile shader', gl.compileShader(vertexShader));
e('compile shader', gl.compileShader(fragShader));
e('attach shader', gl.attachShader(program, vertexShader));
e('attach shader', gl.attachShader(program, fragShader));
e('link program', gl.linkProgram(program));

// Setup texture
var img = new Image();
var texture;
img.onload = function() {
  texture = e('create texture', gl.createTexture());

  e('bind texture', gl.bindTexture(gl.TEXTURE_2D, texture));
  e('pixel store', gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true));

  e('tex image 2d', gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGB, gl.RGB, gl.UNSIGNED_BYTE, img));
  e('tex param mag filter', gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST));
  e('tex param min filter', gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST));
  e('bind texture', gl.bindTexture(gl.TEXTURE_2D, null));
};

// TODO: this will not always be sync!
img.src = "../example/white32.tga";

var squareTextureBuffer = e('create texture buffer', gl.createBuffer());
e('bind texture buffer', gl.bindBuffer(gl.ARRAY_BUFFER, squareTextureBuffer));
e('buffer texture coords', gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(textureCoords), gl.STATIC_DRAW));


if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
  console.log("Could not link program.\n Error:", gl.getError());
  console.log(gl.getProgramInfoLog(program));
  fail();
}


var attr = e('attribute location', gl.getAttribLocation(program, "aVertexPosition"));
var textureAttr = e('texture location', gl.getAttribLocation(program, "aTextureCoord"));

var samplerUniform = e('get uSampler uniform', gl.getUniformLocation(program, "uSampler"));

var vertexBuffer = e('create buffer', gl.createBuffer());
e('bind buffer', gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer));
e('buffer data', gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW));


e('viewport', gl.viewport(0, 0, 300, 300));

e('use program', gl.useProgram(program));
e('enable vertex attrib array', gl.enableVertexAttribArray(attr));

var a = 2000;
while(a--) {


  e('bind buffer', gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer));
  e('vertex pointer', gl.vertexAttribPointer(attr, 3, gl.FLOAT, false, 0, 0));

  e('bind texture buffer', gl.bindBuffer(gl.ARRAY_BUFFER, squareTextureBuffer));
  e('vertex point texture', gl.vertexAttribPointer(textureAttr, 2, gl.FLOAT, false, 0, 0));

  e('set active texture', gl.activeTexture(gl.TEXTURE0));
  e('bind texture', gl.bindTexture(gl.TEXTURE_2D, texture));
  e('uniformi', gl.uniform1i(samplerUniform, 0));

  e('enable depth test', gl.enable(gl.DEPTH_TEST));
  e('clear color', gl.clearColor(0.5, 0.5, 0.5, 1));
  e('clear', gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT));
  e('draw arrays', gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4));
  e('flush', gl.flush());
}
console.log("DONE");