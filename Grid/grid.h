#ifndef GRID_H
#define GRID_H

#include "../Drawer/drawer.h"
#include "../Units/building.h"

class Grid{
public:
  Grid();
  Grid( Drawer &d );

  void update();
  void hover_building(int, int);
  void build_building();
  void draw_buildings();

  void lock();
  void unlock();

private:
  bool locked;
  int x_rounded;
  int y_rounded;
  int determine_x_rounded(int);
  int determine_y_rounded(int);

  Drawer drawer;
  Building building;
};

#endif
