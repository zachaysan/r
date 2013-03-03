#include <iostream>
#include <string>
#include <sstream>

#include "grid.h"

Grid::Grid( Drawer &d ){
  drawer = d;
  locked = false;
  x_rounded = 0;
  y_rounded = 0;
};

Grid::Grid(){};

int Grid::determine_x_rounded( int mouse_x ){
  return (mouse_x * 4 / (62 * 4 + 3)) * (62 * 4 + 3 ) / 4 + 5;
}

int Grid::determine_y_rounded( int mouse_y ){
  return ( mouse_y * 4 / (62 * 4 + 3)) * (62 * 4 + 3 ) / 4 + 3;
}

void Grid::lock(){
  locked = true;
}

void Grid::unlock(){
  locked = false;
}

void Grid::hover_building( int mouse_x, int mouse_y ){
  if( not locked ){
    x_rounded = determine_x_rounded( mouse_x );
    y_rounded = determine_y_rounded( mouse_y );
  }
};

void Grid::update(){
  drawer.draw_building(x_rounded, y_rounded);
  draw_buildings();
}

void Grid::draw_buildings(){
  drawer.draw_building(building.x, building.y);
}

void Grid::build_building(){
  if( locked ){
    // lol... Yeah, need to figure out how to do
    // multiple buildings properly...
    building = Building(x_rounded, y_rounded);
  }
};
