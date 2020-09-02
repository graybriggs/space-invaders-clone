
#include "enemy_controller.h"

EnemyController::EnemyController()
	: dir(Direction::LEFT)
{

	// construct enemies and lay them out on the screen in an 8x3 array fashion
	// with the green enemies on the top, blue in the middle and red on the bottom
	int x = 100, y = 100;
	for (int i = 0; i < 24; ++i) {
		util::rect r(x, y, 64, 64);

		// std::move to avoid making temporary copies
		if (i >= 0 && i < 8)
			enemies.push_back(std::move(std::make_shared<Enemy>(r, "./images/green_alien.bmp", 30)));
		else if (i >= 8 && i < 16)
			enemies.push_back(std::move(std::make_shared<Enemy>(r, "./images/blue_alien.bmp", 20)));
		else if (i >= 16)
			enemies.push_back(std::move(std::make_shared<Enemy>(r, "./images/red_alien.bmp", 10)));

		if (x >= 800) {
			x = 100;
			y += 100;
		}
		else {
			x += 100;
		}
	}

}

EnemyController::~EnemyController() {

}


void EnemyController::doEnemyLogic(double delta) {

	moveEnemies(delta);
	enemyScreenCollision();
	isEnemyOnBottomLayer();
}

int EnemyController::enemyBulletCollision(const std::shared_ptr<Bullet> bul) {

	for (auto& a : enemies) {
		if (!a->isDead()) {
			if (util::aabbCollision(bul->getBoundingBox(), a->getBoundingBox())) {
				a->setDead();
				bul->setInactive();
				return a->getValue();
			}
		}
	}
	return 0;
}

void EnemyController::isEnemyOnBottomLayer() {

	// get the top, middle and bottom enemy of each column
	// and check if they're dead. if not then enable the bottom
	// most enemy to drop bombs
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
}

//// TEST

void EnemyController::testDropBombs() {

	for (auto& a : enemies) {

		a->dropBomb();
	}
}

////////

void EnemyController::renderEnemies() const {

	for (auto& a : enemies) {
		a->render();
	}
}

bool EnemyController::allEnemiesDead() {

	for (auto& a : enemies) {
		if (!a->isDead())
			return false;
	}
	return true;
}

void EnemyController::resetAllEnemies() {

	for (auto& a : enemies) {
		a->setAlive();
	}
}

// private member functions

void EnemyController::moveEnemies(double delta) {
	// move the enemies
	for (auto& a : enemies) {
		if (dir == Direction::LEFT)
			a->moveBy(-5.0 * delta, 0.0);
		else if (dir == Direction::RIGHT)
			a->moveBy(5.0 * delta, 0.0);
	}
}

void EnemyController::enemyScreenCollision() {

	for (auto& a : enemies) {
		if (!a->isDead()) {
			if (a->getBoundingBox().x < 0.0)
				dir = Direction::RIGHT;
			else if (a->getBoundingBox().x + a->getBoundingBox().w >= 1024.0)
				dir = Direction::LEFT;
		}
	}
}



