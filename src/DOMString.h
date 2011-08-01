/**
  WebGL Standalone

  DOMString.h

  Released under the MIT license (see: ../LICENSE)
  Copyright Elijah Insua <tmpvar@gmail.com> 2011
**/
#ifndef _INCLUDED_DOMString_
#define _INCLUDED_DOMString_

#include "arch/wrapper.h"

#include <string>

using namespace std;

class DOMString {
  public:
    string value;
    DOMString();
    ~DOMString();
};

#endif