#ifndef DRAWER_H
#define DRAWER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <sstream>

class Drawer{
private:
  SDL_Surface* load_image(std::string);
public:
  Drawer();
  Drawer( SDL_Surface* );
  void apply_surface(int, int, SDL_Surface*, SDL_Rect*);
  void draw_building(int, int);
  void draw_background();
  void update();
  SDL_Surface* main_screen;
  SDL_Surface* main_tile;  
  SDL_Surface* building_tile;
};

#endif
