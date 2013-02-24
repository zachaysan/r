#include "SDL/SDL.h"

#include <iostream>
#include <string>
#include <sstream>

#include "mouse.h"

int mouse_input( SDL_MouseMotionEvent *mouse_motion, 
		 int &mouse_x,
		 int &mouse_y ){
  mouse_x = mouse_motion->x;
  mouse_y = mouse_motion->y;

  return NO_FURTHER_ACTION;
}
