#ifndef GRID_H
#define GRID_H

#include "../Drawer/drawer.h"

class Grid{
public:
  Grid();
  Grid( Drawer &d );
  Drawer drawer;
  void hover_building(int, int);
};

#endif
