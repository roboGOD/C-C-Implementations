// Instructions::
//
// 		Change the path of the image before running
//
// That's It.

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gImage = NULL;


// Change the path to the bmp image
char path[] = "Images//Daft Punk.bmp";
const int WIDTH = 600;
const int HEIGHT = 600;

bool init();
bool loadMedia();
void close();

bool init()
{
	bool success = true;

	if(SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
		printf("SDL could not be initialized! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow( "Daft Punk!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
			gScreenSurface = SDL_GetWindowSurface( gWindow );
	}
	return success;
}


bool loadMedia()
{
	bool success = true;

	gImage = SDL_LoadBMP(path);
	if( gImage == NULL )
	{
		printf("Could not load the image! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	
	return success;
}


void close()
{
	SDL_FreeSurface( gImage );
	gImage = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}

int main( int argc, char* args[] )
{
	if(!init())
		printf("Failed to initialize!\n");
	else
	{
		if(!loadMedia())
			printf("Failed to load media!\n");
		else
		{
			SDL_BlitSurface( gImage, NULL, gScreenSurface, NULL );
			
			SDL_UpdateWindowSurface( gWindow );

			SDL_Delay( 5000 );
		}
	}

	close();

	return 0;
}


