#include "util.h"
#include <iostream>
#include "arch/wrapper.h"

using namespace std;


void e(const char *call) {
  int err = glGetError();
  if (err < 0) {
    cout << "ERROR: calling" << call << " resulted in '" << gluErrorString(err) << "'( code: " << err << " )" << endl;
  }
}