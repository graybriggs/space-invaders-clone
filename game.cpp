
#include "game.h"


const int Game::SCREEN_W = 1024;
const int Game::SCREEN_H = 675;
const int Game::SCREEN_BPP = 32;


Game::Game()
	:
	player(Player(util::rect(SCREEN_W / 2, SCREEN_H - 100, 96, 32), "./images/player_ship.bmp")),
	ec(EnemyController()),
	bullet(std::make_shared<Bullet>(util::rect(0, 0, 8, 32), "./images/bullet.bmp"))
{
}

void Game::initGame() {

}

void Game::input(SDL_Event event) {
	player.input(event);
}

void Game::logic(const double delta) {

	if (player.fireBullet()) {
		bullet->fire(player.getBoundingBox()); // fire at the player position
	}

	ec.doEnemyLogic(delta);
	player.logic(delta);
	bullet->logic(delta);
	int score = ec.enemyBulletCollision(bullet);
	player.incrementScore(score);

	if (ec.allEnemiesDead())
		ec.resetAllEnemies();

	ec.testDropBombs();

}

void Game::render() const {

	player.render();
	ec.renderEnemies();
	bullet->render();
}