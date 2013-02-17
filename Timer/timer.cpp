#include "SDL/SDL.h"

class Timer{
private:
  int start_ticks;
  int paused_ticks;
  bool paused;
  bool started;

public:
  Timer();

  void start();
  void stop();
  void pause();
  void unpause();

  int get_ticks();

  bool is_started();
  bool is_paused();
};

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
  if( started ){
    if( paused ){
      return paused_ticks;
    } else {
      return SDL_GetTicks() - start_ticks;
    }
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
