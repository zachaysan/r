#include "SDL/SDL.h"

// import standard c++ stuff
#include <iostream>
#include <string>
#include <sstream>

// contains definitions for ints
#include "signals.h"
#include "keyboard.h"

int keyboard_input( SDL_KeyboardEvent *key ){
  bool ctrl = (key->keysym.mod & KMOD_CTRL);
  if( ctrl and key->keysym.sym == SDLK_w ){
    return QUIT_SIGNAL;
  }
  if( ctrl and key->keysym.sym == SDLK_c ){
    return QUIT_SIGNAL;
  }
  if( key->keysym.sym == SDLK_RETURN ){
    return ACCEPT_ACTION;
  }
  if( key->keysym.sym == SDLK_ESCAPE ){
    return CANCEL_STARTED_ACTION_AT_LOCATION;
  }
  if( key->keysym.sym == SDLK_F11 ){
    return MAX_SCREEN;
  }
  return NO_ACTION;
}
