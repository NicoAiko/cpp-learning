#include "Runner.h"
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Runner::Runner() {
	LOG("Starting application...");

	SDL_Window *window = NULL;
	SDL_Surface *screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		LOG("SDL could not be initialized!\nSDL_Error: ");
		LOG(SDL_GetError());
		
		return;
	}

	window = SDL_CreateWindow("SQL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		LOG("Window could not be created!\n");
		LOG(SDL_GetError());

		return;
	}

	screenSurface = SDL_GetWindowSurface(window);
	
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);

	SDL_Event e;
	bool quit = false;

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
				}
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
}

Runner::~Runner() {
	LOG("Finishing application...");

	LOG_DECONSTRUCT;
}