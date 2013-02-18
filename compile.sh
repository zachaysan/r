#!/bin/bash

g++ -c Logger/logger.cpp 
g++ -c Timer/timer.cpp
g++ -c Input/keyboard.cpp
g++ -c main.cpp
g++ main.o keyboard.o timer.o logger.o -o main -lSDL -lSDL_image -lSDL_ttf
