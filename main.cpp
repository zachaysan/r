// import SDL
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

// import standard c++ stuff
#include <iostream>
#include <string>
#include <sstream>

// import other classes

// Timer()
#include "Logger/logger.h"
// keyboard_input()
#include "Timer/timer.h"
// log()
#include "Input/keyboard.h"
// set constants
const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 680;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 1000;

// set globals
Timer timer;
SDL_Event event;
SDL_Surface *screen = NULL;

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
			     SDL_SWSURFACE );

  if( screen == NULL ){
    return 2;
  }
}

// load files (maybe in linked files)

// init main
int main( int argc, char* args[] ){
  init();
  log(timer.get_ticks());
  SDL_Delay( 2 );
  log(timer.get_ticks());
  bool quit = false;
  while( not quit ){
    while( SDL_PollEvent( &event ) ){
      if( event.type == SDL_QUIT ){
	quit = true;
      }
      if( event.type == SDL_KEYDOWN ){ 
	quit = quit or not keyboard_input( &event.key );
      }
    }
  }
  log("Program ended successfully");
  return 0;
}
// clean up
