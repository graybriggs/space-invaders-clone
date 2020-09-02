
#include <SDL.h>

#include "game.h"

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	SDL_SetVideoMode(Game::SCREEN_W, Game::SCREEN_H, Game::SCREEN_BPP, SDL_SWSURFACE);

	SDL_Event event;

	bool done = false;

	Game game;

	const float fps = 60.0f;
	const float dt = 1.0f / fps; // fixed timestep of 1/60th of a second
	float accumulator = 0.0f;
	float frameStart = static_cast<float>(SDL_GetTicks());

	while (!done) {

		const float currentTime = static_cast<float>(SDL_GetTicks());
		accumulator += currentTime - frameStart;
		frameStart = currentTime;

		// poll for input
		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				done = true;
			}
			game.input(event);
		}

		if (accumulator > 0.2f)
			accumulator = 0.2f;

		while (accumulator > dt) {

			game.logic(dt);
			accumulator -= dt;
		}

		// blank the screen with black before rendering
		SDL_FillRect(SDL_GetVideoSurface(), NULL, 0x0);

		game.render();

		SDL_Flip(SDL_GetVideoSurface());
	}

	SDL_Quit();
	
}