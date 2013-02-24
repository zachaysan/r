DEFINITIONS

global  -> Completely game wide, server is cannon, but not required
local   -> Just this computer, volatile, since this may need to change upon 
       	   updates from the entire system
server  -> Completely game wide, always requested

DONE

main.cpp - includes and starts everything.
Timer/timer.cpp - the local game wide clock

NEEDED

Drawer/drawer.cpp - tells units to blit to the primary surface
Allocator/allocator.cpp - determines the flow of resources throughout the game,
			  uses a DAG (or possibly a DG) to determine the order of 
			  resource movement.
Camera/camera.cpp - manages which sub-rectangle of the surface it is to draw,
		    handles transitions from one area of the surface to the other
Blocks/basic.cpp - the fundamental block (unit, building, etc) implemented in
		   a state machine type of way. During construction, is passed
		   a pointer to the canvas so that it may draw itself.

Menu/master.cpp - shows the important stuff: what blocks you could build, the amount
		  of resources you have, etc.
Menu/detail.cpp - the block-selected menu, with options to recycle etc.
Menu/settings.cpp - the game wide settings menu

Input/mouse.cpp - converts mouse events to game events. Pubsub to blocks/camera based on
		  local coordinate system.
Input/keyboard.cpp - converts keyboard events to game events. Pubsub based on both
		     global and current active state (if item is currently active it
		     takes the input first).

Sound/fx.cpp - handles the sound effects.
Sound/music.cpp - handles the music.

OTHER NEEDED THINGS

Some place to put the music/sound/images.

Some place to put the saved game data.

A way to create saved game data.

A way to generate maps.

A way to communicate map state throughout the game.
