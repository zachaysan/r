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

// set globals
Timer timer;
SDL_Event event;

// init
int init(){
  timer = Timer();
  timer.start();
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
	quit = quit or keyboard_input( &event.key );
      }
    }
  }
  log("Program ended successfully");
  return 0;
}
// clean up
