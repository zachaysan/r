// import SDL
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

// import standard c++ stuff
#include <iostream>
#include <string>
#include <sstream>

// import other classes

#include "Logger/logger.h" // log()
#include "Timer/timer.h" // Timer()

#include "Input/signals.h" // input signals (eg. NO_ACTION)
#include "Input/keyboard.h" // keyboard_input()
#include "Input/mouse.h" // keyboard_input()

#include "Drawer/drawer.h" // 
#include "Grid/grid.h"

// set constants
const int SCREEN_WIDTH = 1440;
const int SCREEN_HEIGHT = 900;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 50;

// set globals
Timer timer;
Drawer drawer;
Grid grid;
SDL_Event event;
SDL_Surface* screen = NULL;
int mouse_x;
int mouse_y;
// init
int init(){
  timer = Timer();
  timer.start();
  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
    return 1;
  }

  screen = SDL_SetVideoMode( SCREEN_WIDTH,
			     SCREEN_HEIGHT,
			     SCREEN_BPP,
			     SDL_SWSURFACE | SDL_RESIZABLE | SDL_FULLSCREEN);


  if( screen == NULL ){
    return 2;
  }
  drawer = Drawer(screen);
  drawer.update();
  grid = Grid(drawer);
  return 0;
}

// load files (maybe in linked files)

// init main
int main( int argc, char* args[] ){
  init();
  log(timer.get_ticks());
  SDL_Delay( 2 );
  log(timer.get_ticks());
  drawer.draw_background();
  bool quit = false;
  int action = NO_ACTION;
  drawer.draw_background();

  while( not quit ){
    drawer.draw_background();	  
    grid.hover_building(mouse_x, mouse_y);
    grid.update();

    while( SDL_PollEvent( &event ) ){
      if( event.type == SDL_QUIT ){
	quit = true;
      }
      if( event.type == SDL_KEYDOWN ){ 
	action = keyboard_input( &event.key );
      }
      if( event.type == SDL_MOUSEMOTION ){
	action = mouse_motion_input( &event.motion,
				     mouse_x,
				     mouse_y );
      }
      if( event.type == SDL_MOUSEBUTTONDOWN or
	  event.type == SDL_MOUSEBUTTONUP ){
	action = mouse_button_input( &event.button,
				     mouse_x,
				     mouse_y );
      }
      
      // Handle actions (move me somewhere better)
      if( action == START_ACTION_AT_LOCATION ){
	grid.lock();
      }
      if( action == CANCEL_STARTED_ACTION_AT_LOCATION ){
	grid.unlock();
      }
      if( action == FINISH_STARTED_ACTION_AT_LOCATION ){
	grid.build_building();
	grid.unlock();
      }
      quit = quit or not action;
    }
    drawer.update();
  }
  log("Program ended successfully");
  return 0;
}
// clean up
