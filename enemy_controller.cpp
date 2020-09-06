
#include <iterator>

#include "enemy_controller.h"

#include "enemy.h"
#include "globals.h"
#include "utility.h"
#include "renderer.h"


EnemyController::EnemyController(Sprite* sprite)
	: dir(Direction::LEFT),
	enemy_spritesheet(sprite)
{


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
			util::Rect r(x, y, 32, 32);
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
	

}

void EnemyController::logic(double delta) {

	moveEnemies(delta);
	enemyScreenCollision();
	isEnemyOnBottomLayer();
	for (auto& e : enemies)
		e.logic(delta);
}

void EnemyController::enemyBulletCollision(Bullet& bullet) {

	for (auto& enemy : enemies) {
		if (!enemy.isDead()) {
			if (util::aabbCollision(enemy.getBoundingBox(), bullet.getBoundingBox())) {
				enemy.setDead();
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
				break;
			}
		}
	}
	
	for (auto& a : enemies) {
		if (a.canDropBombs()) {

		}
	}

}

//// TEST

void EnemyController::testDropBombs() {

	for (auto& enemy : enemies) {
		enemy.dropBomb();
	}
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
			enemy.moveBy(-2.0 * delta, 0.0);
		else if (dir == Direction::RIGHT)
			enemy.moveBy(2.0 * delta, 0.0);
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
}