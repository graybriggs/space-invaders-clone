
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
	const int ENEMIES_PER_ROW = 11;

	int x = DISPLACEMENT_X;
	int y = DISPLACEMENT_Y;

	for (int i = 0; i < TOTAL_ENEMIES / ENEMIES_PER_ROW; ++i) {
		for (int j = 0; j < ENEMIES_PER_ROW; ++j) {
			//SDL_Rect r = util::prepare_rect(x, y, 32, 32);
			util::Rect r(x, y, 32, 32);
			Enemy enemy(enemy_spritesheet, r);
			enemy.setAlive();
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


void EnemyController::isEnemyOnBottomLayer() {

	// get the top, middle and bottom enemy of each column
	// and check if they're dead. if not then enable the bottom
	// most enemy to drop bombs

	/*
	auto it = enemies.begin();
	for (; it != enemies.begin() + 8; it++) {
		std::shared_ptr<Enemy>& top = *it;
		std::shared_ptr<Enemy>& mid = *(it + 8);
		std::shared_ptr<Enemy>& bottom = *(it + 16);

		if (!bottom->isDead())
			bottom->setCanDropBombs(true);
		else if (!mid->isDead())
			mid->setCanDropBombs(true);
		else if (!top->isDead())
			top->setCanDropBombs(true);
	}
	*/
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