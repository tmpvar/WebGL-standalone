/**
  WebGL Standalone

  WebGLActiveInfo .h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_WebGLActiveInfo _
#define _INCLUDED_WebGLActiveInfo _

#include <gl/gl.h>



class WebGLActiveInfo  {
  public:
    WebGLActiveInfo ();
    ~WebGLActiveInfo ();

    readonly attribute GLint size;
    readonly attribute GLenum type;
    readonly attribute DOMString name;
};

#endif