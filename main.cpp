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
#include "Timer/timer.cpp"
// log()
#include "Logger/logger.cpp"

// set constants

// set globals
Timer timer;

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
  log("Program exitted successfully");
  return 0;
}
// clean up
