// Run it as
//
// 		gcc brensenhamsLineDrawingAlgorithm.c -o pro -lSDL2
// 		./pro
//
// That's it.	

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void plotLineLow(SDL_Renderer* renderer, float x1, float y1, float x2, float y2)
{
	float dx, dy, p;
	int x, y, yi = 1;

	dx = x2-x1;
	dy = y2-y1;

	if(dy < 0)
	{
		yi = -1;
		dy *= -1;
	}

	p = 2*dy - dx;
	x = x1;
	y = y1;

	while(x <= x2)
	{
		SDL_RenderDrawPoint(renderer, x, y);
		SDL_RenderPresent(renderer);
		if(p > 0)
		{
			y += yi;
			p -= 2*dx;
		}
		p += 2*dy;
		x++;
		SDL_Delay(30);
	} 
}

void plotLineHigh(SDL_Renderer* renderer, float x1, float y1, float x2, float y2)
{
	float dx, dy, p;
	int x, y, xi = 1;

	dx = x2-x1;
	dy = y2-y1;

	if(dx < 0)
	{
		xi = -1;
		dx *= -1;
	}

	p = 2*dx - dy;
	x = x1;
	y = y1;

	while(y <= y2)
	{
		SDL_RenderDrawPoint(renderer, x, y);
		SDL_RenderPresent(renderer);
		if(p > 0)
		{
			x += xi;
			p -= 2*dy;
		}
		p += 2*dx;
		y++;
		SDL_Delay(30);
	} 
}


void plotLine(SDL_Renderer* renderer)
{
	float x1, y1, x2, y2, dx, dy;

	printf("\nEnter x1, y1: ");
	scanf("%f %f", &x1, &y1);

	printf("\nEnter x2, y2: ");
	scanf("%f %f", &x2, &y2);

	dx = x2-x1;
	dy = y2-y1;

	if(abs(dy) < abs(dx))
	{
		if(x1 > x2)
			plotLineLow(renderer, x2, y2, x1, y1);
		else
			plotLineLow(renderer, x1, y1, x2, y2);
	}
	else
	{
		if(y1 > y2)
			plotLineHigh(renderer, x2, y2, x1, y1);
		else
			plotLineHigh(renderer, x1, y1, x2, y2);
	}
}

int main(int argc, char* args[])
{
	SDL_Window* window = NULL;
	SDL_Event event;
    SDL_Renderer *renderer;

	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
		printf("SDL could not be initialized! SDL Error: %s\n", SDL_GetError());
	else
	{
		SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		plotLine(renderer);

		SDL_RenderPresent(renderer);
		while (1) {
        	if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            	break;
    	}
	}

	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}



