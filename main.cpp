

#include <SDL.h>
#include <SDL_ttf.h>

#include <memory>

#include "bullet.h"
#include "game.h"
#include "game_score.h"
#include "globals.h"
#include "menu.h"
#include "particle_manager.h"
#include "renderer.h"
#include "sprite.h"
#include "star_field.h"
#include "state.h"
#include "timer.h"

#include "bonus_enemy.h"

int main(int argc, char* argv[]) {
	srand(time(nullptr));
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	TTF_Init();
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

	auto player_sprite = load_sprite(renderer, "./images/player_ship.bmp");
	Player player(player_sprite.get(), util::Rect(global::SCREEN_W / 2, global::SCREEN_H - 100, 32, 16));

	auto game_score = std::make_unique<GameScore>();
	game_score->init_digits(renderer);

	auto enemy_sprite = load_sprite(renderer, "./images/aliens.bmp");
	EnemyController enemy_controller(enemy_sprite.get(), game_score.get());
	enemy_controller.setupEnemies();

	BonusEnemy bonus_enemy(player_sprite.get(), util::Rect(global::SCREEN_W / 2, global::SCREEN_H - 650, 32, 16));
	bonus_enemy.setImageClipBox(util::prepare_rect(0, 0, 32, 16));
	BonusEnemyController bonus_enemy_controller(&bonus_enemy, game_score.get());

	auto bullet_sprite = load_sprite(renderer, "./images/bullet.bmp");
	Bullet bullet(bullet_sprite.get(), util::Rect(0, 0, 2, 24));

	auto bomb_sprite = load_sprite(renderer, "./images/bomb.bmp");
	enemy_controller.setupBombs(bomb_sprite.get());

	Starfield starfield;
	setup_starfield(starfield);

	//ParticleManager particle_manager;

	GameStates game_state = GameStates::MENU;
	Menu menu(renderer, game_state);
	
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

			game_state = menu.input(event);

			if (game_state == GameStates::GAME) {
				//game.input(event);
				player.input(event);
			}
		}

		if (accumulator > 0.2f)
			accumulator = 0.2f;

		while (accumulator > dt) {
			
			update_starfield(starfield, dt);
			player.logic(dt);
			
			if (player.hasFired() && !bullet.isActive()) {
				bullet.fire(player.getBoundingBox());
				player.fireWait();
			}
			

			bullet.logic(dt);
			enemy_controller.logic(dt);
			enemy_controller.bombDropController(currentTime);
			enemy_controller.enemyBulletCollision(bullet);
			bonus_enemy_controller.logic(dt);
			
			

			//particle_manager.logic(dt);

			accumulator -= dt;
		}
		clear_screen(renderer);

		render_starfield(renderer, starfield);

		bonus_enemy_controller.render_bonus_enemy(renderer);
		//render_entity(renderer, bonus_enemy);

		enemy_controller.renderEnemies(renderer);
		render_entity(renderer, player);

		if (bullet.isActive())
			render_entity(renderer, bullet);

		//render_particles(renderer, particle_manager.getParticles());


		if (game_state == GameStates::MENU) {

			SDL_Rect r = menu.get_title_text_entity().rect;
			SDL_RenderCopy(renderer, menu.get_title_text_entity().texture, nullptr, &r);

			r = menu.get_score_text_entity().rect;
			SDL_RenderCopy(renderer, menu.get_score_text_entity().texture, nullptr, &r);

			r = menu.get_high_score_text_entity().rect;
			SDL_RenderCopy(renderer, menu.get_high_score_text_entity().texture, nullptr, &r);

			r = menu.get_start_msg_text_entity().rect;
			SDL_RenderCopy(renderer, menu.get_start_msg_text_entity().texture, nullptr, &r);

			r = menu.get_version_text_entity().rect;
			//SDL_RenderCopy(renderer, menu.get_version_text_entity().texture, nullptr, &r);
		}

		game_score->render_game_score(renderer);
		game_score->render_high_score(renderer);

		//game.render();
		SDL_RenderPresent(renderer);

	}

	SDL_Quit();

	return 0;
}
