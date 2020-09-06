#pragma once

#ifndef ENEMY_CONTROLLER_HPP
#define ENEMY_CONTROLLER_HPP

#include <vector>

#include "bullet.h"

class Enemy;

class EnemyController {
	
public:
	static constexpr int TOTAL_ENEMIES = 55;
	static constexpr int ENEMIES_PER_ROW = 11;
	
	enum Direction { LEFT, RIGHT };

	EnemyController(Sprite*);
	~EnemyController();

	void setupEnemies();
	void resetEnemies();

	void logic(double delta);
	void enemyBulletCollision(Bullet&);
	void isEnemyOnBottomLayer();
	////
	void testDropBombs();
	////
	bool allEnemiesDead();

	void renderEnemies(SDL_Renderer* renderer);

private:

	void moveEnemies(double delta);
	void enemyScreenCollision();
	std::size_t to1D(int x, int y);

	Sprite* enemy_spritesheet;
	std::vector<Enemy> enemies;
	Direction dir;
};


#endif