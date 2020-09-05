

#include <SDL.h>

#include <memory>

#include "bullet.h"
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

	SDL_Texture* tex = nullptr;
	load_spritesheet(renderer, &tex, "./images/player_ship.bmp");
	auto generic_sprite = std::make_unique<Sprite>(tex, util::Rect(0,0,32,32));
	Player player(generic_sprite.get(), util::Rect(global::SCREEN_W / 2, global::SCREEN_H - 100, 32, 16));
	Bullet bullet(generic_sprite.get(), util::Rect(0, 0, 4, 24));

	SDL_Texture* enemy_tex;
	load_spritesheet(renderer, &enemy_tex, "./images/green_alien.bmp");
	auto enemy_sprite = std::make_unique<Sprite>(enemy_tex, util::Rect(0, 0, 32, 32));
	EnemyController enemy_controller(enemy_sprite.get());
	enemy_controller.setupEnemies();

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
			player.input(event);
		}

		if (accumulator > 0.2f)
			accumulator = 0.2f;

		while (accumulator > dt) {

			player.logic(dt);
			
			if (player.hasFired() && !bullet.isActive()) {
				bullet.fire(player.getBoundingBox());
				player.fireWait();
			}
			bullet.logic(dt);
			enemy_controller.logic(dt);
			enemy_controller.enemyBulletCollision(bullet);

			accumulator -= dt;
		}
		clear_screen(renderer);

		enemy_controller.renderEnemies(renderer);
		render_entity(renderer, player);

		if (bullet.isActive())
			render_entity(renderer, bullet);

		//game.render();
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(tex);
	SDL_Quit();

	return 0;
}
