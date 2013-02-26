#include <iostream>
#include <string>
#include <sstream>

#include "grid.h"

Grid::Grid( Drawer &d ){
  drawer = d;
};

Grid::Grid(){};

void Grid::hover_building(int mouse_x, int mouse_y){
  int x_rounded = (mouse_x * 4 / (62 * 4 + 3)) * (62 * 4 + 3 ) / 4 + 5;
  int y_rounded = (mouse_y * 4 / (62 * 4 + 3)) * (62 * 4 + 3 ) / 4 + 3;
  drawer.draw_building(x_rounded, y_rounded);
};

/*
void Grid::build_building(int mouse_x, int mouse_y){
  building.build(mouse_x, mouse_y);
}
*/
