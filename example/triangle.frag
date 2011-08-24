#ifdef GL_ES
precision highp float;
#endif

varying vec2 vTextureCoord;
uniform sampler2D sampler;

void main(void) {
    gl_FragColor = texture2D(sampler, vTextureCoord);
}