
#include <iterator>
#include <memory>

#include "enemy_controller.h"

#include "bomb.h"
#include "enemy.h"
#include "game_score.h"
#include "globals.h"
#include "utility.h"
#include "renderer.h"


EnemyController::EnemyController(Sprite* sprite, GameScore* gs)
	: dir(Direction::LEFT),
	enemy_spritesheet(sprite),
	readyToDropBomb(false),
	game_score(gs)
{
	last_time = static_cast<float>(SDL_GetTicks());
}

EnemyController::~EnemyController() {

}

void EnemyController::setupEnemies() {
	// construct enemies and lay them out on the screen in an 11x5 array fashion


	const int DISPLACEMENT_X = 48;
	const int DISPLACEMENT_Y = 48;

	int x = DISPLACEMENT_X;
	int y = DISPLACEMENT_Y;

	for (int i = 0; i < TOTAL_ENEMIES / ENEMIES_PER_ROW; ++i) {
		for (int j = 0; j < ENEMIES_PER_ROW; ++j) {
			util::Rect r((float)x, (float)y, 32.0f, 32.0f);
			Enemy enemy(enemy_spritesheet, r);
			enemy.setAlive();
			enemy.setCanDropBombs(false);
			enemies.push_back(enemy);

			x += DISPLACEMENT_X;
		}
		x = DISPLACEMENT_X;
		y += DISPLACEMENT_Y;
	}
}


void EnemyController::resetEnemies() {
	enemies.clear();
	setupEnemies();
}

void EnemyController::setupBombs(Sprite* s) {

	bomb = std::make_unique<Bomb>(s, util::Rect(0, 0, 8, 24));
	bomb->setImageClipBox({ 0, 0, 8, 24 });
	/*
	for (int i = 0; i < 11; ++i) {
		auto bomb = std::make_unique<Bomb>(s, util::Rect(0, 0, 8, 24));
		bomb->setImageClipBox({ 0, 0, 8, 24 });
		bombs.push_back(bomb);
	}
	*/
}

void EnemyController::logic(const double delta) {

	moveEnemies(delta);
	enemyScreenCollision();
	isEnemyOnBottomLayer();

	for (auto& e : enemies) {
		e.logic(delta);
	}

	//bomb->logic(delta);

	bomb->isActive();
	bomb->moveBy(0, 3.0 * delta);
	/*
	for (auto& b : bombs) {
		if (b->isActive()) {
			b->moveBy(0, 3.0 * delta);
		}
	}
	*/

	if (allEnemiesDead()) {
		game_score->level_clear();
		resetEnemies();
	}
}

void EnemyController::enemyBulletCollision(Bullet& bullet) {
	for (auto& enemy : enemies) {
		if (!enemy.isDead()) {
			if (util::aabbCollision(enemy.getBoundingBox(), bullet.getBoundingBox())) {
				enemy.setDead();

				game_score->enemy_killed(30);

				bullet.setInactive();
			}
		}
	}
}


std::size_t EnemyController::to1D(int x, int y) {
	return y * ENEMIES_PER_ROW + x;
}


void EnemyController::isEnemyOnBottomLayer() {

	for (int x = 0; x < ENEMIES_PER_ROW; ++x) {
		for (int y = 4; y >= 0; --y) {

			std::size_t pos = to1D(x, y);
			Enemy& e = enemies[pos];

			if (!e.isDead()) {
				e.setCanDropBombs(true);
				bottom_enemies.push_back(&e);
				break;
			}
		}
	}
}

//// TEST

void EnemyController::bombDropController(const float current_time) {

	if (current_time > last_time + 1000.0f) {

		if (enemies.size()) {

			int rand_enemy = rand() % bottom_enemies.size();
			Enemy* e = bottom_enemies[rand_enemy];
			util::Rect r = e->getBoundingBox();
			util::Rect bomb_pos(r.pos_x + (r.w / 2),
								r.pos_y + r.h, 4, 24);

			bomb->setPosition(bomb_pos);
			bomb->setActive();
		}
		last_time = current_time;
	}
	bottom_enemies.clear();
}

bool EnemyController::allEnemiesDead() {

	for (auto& enemy : enemies) {
		if (!enemy.isDead())
			return false;
	}
	return true;
}

// private member functions

void EnemyController::moveEnemies(double delta) {

	for (auto& enemy : enemies) {
		if (dir == Direction::LEFT)
			enemy.moveBy(-1.0 * delta, 0.0);
		else if (dir == Direction::RIGHT)
			enemy.moveBy(1.0 * delta, 0.0);
	}
}

void EnemyController::enemyScreenCollision() {

	for (auto& enemy : enemies) {
		if (!enemy.isDead()) {
			if (util::collisionRectScreenLeft(enemy.getBoundingBox(), 0))
				dir = Direction::RIGHT;
			else if (util::collisionRectScreenRight(enemy.getBoundingBox(), global::SCREEN_W))
				dir = Direction::LEFT;
		}
	}
}

void EnemyController::renderEnemies(SDL_Renderer* renderer) {

	for (auto& enemy : enemies) {
		if (!enemy.isDead()) {
			render_entity(renderer, enemy);
		}
	}

	render_entity(renderer, *(bomb.get()));
}