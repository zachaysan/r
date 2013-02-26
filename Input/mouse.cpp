#include "SDL/SDL.h"

#include <iostream>
#include <string>
#include <sstream>

#include "signals.h"
#include "mouse.h"

int mouse_motion_input( SDL_MouseMotionEvent *mouse_motion, 
		 int &mouse_x,
		 int &mouse_y ){
  mouse_x = mouse_motion->x;
  mouse_y = mouse_motion->y;

  return NO_ACTION;
}

int mouse_button_input( SDL_MouseButtonEvent *mouse_button,
			int &mouse_x,
			int &mouse_y ){
  bool left_button = SDL_BUTTON_LEFT == mouse_button->button;
  if( left_button and mouse_button->state == SDL_RELEASED ){
    return ACTION_AT_LOCATION;
  }
  return NO_ACTION;
}
