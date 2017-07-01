
#include "argtools.h"

#include <string>

std::string getArg(int argc, char* argv[], int index) {
  if (index < 0 || index >= argc) {
    return NULL;
  }

  std::string s(argv[index]);

  return s;

}
