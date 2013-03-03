#!/bin/bash

g++ Logger/logger.cpp -c -Wall &&
g++ Timer/timer.cpp -c -Wall &&
g++ Input/keyboard.cpp -c -Wall &&
g++ Input/mouse.cpp -c -Wall &&
g++ Drawer/drawer.cpp -c -Wall &&
g++ Units/building.cpp -c -Wall &&
g++ Grid/grid.cpp -c -Wall &&
g++ main.cpp -c -Wall &&
g++ main.o logger.o timer.o keyboard.o mouse.o drawer.o building.o grid.o -o main -lSDL -lSDL_image -lSDL_ttf -Wall
