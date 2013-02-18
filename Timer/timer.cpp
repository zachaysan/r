#include "timer.h"

Timer::Timer(){
  start_ticks = 0;
  paused_ticks = 0;
  paused = false;
  started = false;
};

void Timer::start(){
  started = true;
  paused = false;
  start_ticks = SDL_GetTicks();
}

void Timer::stop(){
  started = false;
  paused = false;
}

int Timer::get_ticks(){
  if( started and paused ){
    return paused_ticks;
  } else if( started ) {
    return SDL_GetTicks() - start_ticks;
  } else {
    return 0;
  }
}

void Timer::pause(){
  if( started and not paused ){
    paused = true;
    paused_ticks = SDL_GetTicks() - start_ticks;
  }
}

void Timer::unpause(){
  if( paused ){
    paused = false;
    start_ticks = SDL_GetTicks() - paused_ticks;
    paused_ticks = 0;
  }
}

bool Timer::is_started(){
  return started;
}

bool Timer::is_paused(){
  return paused;
}
