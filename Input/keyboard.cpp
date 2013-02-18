#include "SDL/SDL.h"

// import standard c++ stuff
#include <iostream>
#include <string>
#include <sstream>

int keyboard_input( SDL_KeyboardEvent *key ){
  return 0;
  if( key->keysym.mod & KMOD_CTRL ){
    std::cerr << "lko";
  } else {
    std::cerr << "kiiiill";
  }
  std::cerr << ":D";
  return 0;
}
