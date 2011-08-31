var WebGLRenderingContext = require('../lib/webgl.js').WebGLRenderingContext;
var window = this;
var $ = function() {};
console.error = console.log;
var document = {
  createElement : function() {
    return {
      getContext : function() {
        return new WebGLRenderingContext();
      },
      setTransform : function() {}

    };
  }
};

var navigator = {};
var THREE = require('../example/threejs/three.js');
var w = 300, h = 300;
var container, stats;
var camera, scene, renderer;
var cube, plane;
var targetRotation = 0;
var targetRotationOnMouseDown = 0;
var mouseX = 0;
var mouseXOnMouseDown = 0;
var windowHalfX = 150;
var windowHalfY = 150;

camera = new THREE.Camera( 70, w / h, 1, 1000 );
camera.position.y = 150;
camera.position.z = 100;
camera.target.position.y = 150;

scene = new THREE.Scene();


var sphereMaterial = new THREE.MeshLambertMaterial(
{
    color: 0xFFFFFF
});

// create a new mesh with sphere geometry -
// we will cover the sphereMaterial next!
var sphere = new THREE.Mesh(
   new THREE.PlaneGeometry(10, 10, 2, 2),
   sphereMaterial);

// add the sphere to the scene
scene.addChild(sphere);

// Cube
sphere.position.y = 150;


// create a point light
var pointLight = new THREE.PointLight( 0xFF0000 );

// set its position
pointLight.position.x = 10;
pointLight.position.y = 50;
pointLight.position.z = 100;

// add to the scene
scene.addLight(pointLight);


renderer = new THREE.WebGLRenderer();
renderer.setSize( w, h );
var a = 1000;
while (a--) {
  renderer.render(scene, camera);
  webgl_rendering_context_flush();
}