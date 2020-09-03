
#include <SDL.h>

#include "game.h"
#include "globals.h"
#include "renderer.h"
#include "sprite.h"


int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	SDL_Window* window = window = SDL_CreateWindow(
		"Space Invaders",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		global::SCREEN_W,
		global::SCREEN_H,
		SDL_WINDOW_SHOWN
	);

	Uint32 rendererFlags = SDL_RENDERER_ACCELERATED;
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, rendererFlags);

	SDL_Event event;

	bool done = false;

	//Game game(renderer);

	SDL_Texture* tex = nullptr;
	load_spritesheet(renderer, &tex, "./images/player_ship.bmp");

	Sprite sprite(tex, util::prepare_rect(0,0,32,32));
	Entity entity(&sprite, util::prepare_rect(300, 250, 32, 32));

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
			//game.input(event);
		}

		if (accumulator > 0.2f)
			accumulator = 0.2f;

		while (accumulator > dt) {

			//game.logic(dt);
			accumulator -= dt;
		}

		clear_screen(renderer);

		SDL_Rect bb = util::prepare_rect(100, 100, 32, 32);

		SDL_RenderCopy(renderer, sprite.getTexture(), &(sprite.getClipBox()), &bb);
		render_entity(renderer, entity);
		SDL_RenderPresent(renderer);

		//game.render();
		SDL_RenderPresent(renderer);
		
		//SDL_Flip(SDL_GetVideoSurface());
	}

	SDL_Quit();

	return 0;
}
