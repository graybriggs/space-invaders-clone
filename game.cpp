
#include "game.h"

#include "globals.h"



Game::Game()
	//player(Player(util::prepare_rect(global::SCREEN_W / 2, global::SCREEN_H - 100, 96, 32))
{
	//EnemyController = EnemyController;
	//SDL_Rect bullet_rect = util::prepare_rect(0, 0, 8, 32);
	//bullet(Bullet(bullet_rect, "./images/bullet.bmp"))
}

void Game::initGame() {

}

void Game::input(SDL_Event event) {
	//player.input(event);
}

void Game::logic(const double delta) {

	//if (player.fireBullet()) {
		//bullet->fire(player.getBoundingBox()); // fire at the player position
	//}

	//ec.doEnemyLogic(delta);
	//player.logic(delta);
	//bullet->logic(delta);
	//int score = ec.enemyBulletCollision(bullet);
	//player.incrementScore(score);

	//if (ec.allEnemiesDead())
	//	ec.resetAllEnemies();

	//ec.testDropBombs();

}

void Game::render() const {

	//player.render();
	//ec.renderEnemies();
	//bullet->render();
}