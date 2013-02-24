#include "drawer.h"

Drawer::Drawer( SDL_Surface* screen){
  main_screen = screen;
  std::string main_tile_filename = "images/little_squares.png";
  std::string building_tile_filename = "images/squares.png";
  main_tile = load_image( main_tile_filename );
  building_tile = load_image( building_tile_filename );
};

Drawer::Drawer(){};

void Drawer::update(){
  SDL_Flip(main_screen);
}

void Drawer::draw_building(int x, int y){

  int x_rounded = (x * 4 / (62 * 4 + 3)) * (62 * 4 + 3 ) / 4 - 2;
  int y_rounded = (y * 4 / (62 * 4 + 3)) * (62 * 4 + 3 ) / 4 - 12;

  SDL_Rect clip;
  clip.x = x_rounded * 1 ;// (-52 + (62 * 20));
  clip.y = y_rounded * 1 ; //(-46 + (62 * 10));
  clip.w = 60;
  clip.h = 60;
  apply_surface(x, y, building_tile, &clip);
}

void Drawer::draw_background(){
  apply_surface(-26,-23, NULL, NULL);
  apply_surface(-26+1280 + 6,-23, NULL, NULL);
  apply_surface(-26+1280 +6,-23+800 + 7 - 54, NULL, NULL);
  apply_surface(-26,-23+800 + 7 - 54, NULL, NULL);
}

void Drawer::apply_surface( int x,
			    int y,
			    SDL_Surface* source = NULL,
			    SDL_Rect* clip = NULL){
  SDL_Rect offset;
  if(not source){
    source = main_tile;
  }
  offset.x = x;
  offset.y = y;
  
  SDL_BlitSurface( source, clip, main_screen, &offset );
}

SDL_Surface* Drawer::load_image( std::string filename ){
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;
  loadedImage = IMG_Load( filename.c_str() );
  if( loadedImage != NULL ){
    optimizedImage = SDL_DisplayFormat( loadedImage );
    if( optimizedImage != NULL ){
      Uint32 colorkey = SDL_MapRGB( optimizedImage->format,
				    0, 0xFF, 0xFF );
      SDL_SetColorKey( optimizedImage,
		       SDL_SRCCOLORKEY,
		       colorkey );

    }
    SDL_FreeSurface( loadedImage );
  }
  return optimizedImage;
}
