#pragma once

#ifndef ENEMY_CONTROLLER_HPP
#define ENEMY_CONTROLLER_HPP

#include <memory>
#include <vector>

#include "bullet.h"

class Enemy;
class Bomb;
class GameScore;

class EnemyController {
public:
	static constexpr int TOTAL_ENEMIES = 55;
	static constexpr int ENEMIES_PER_ROW = 11;
	
	enum class Direction { LEFT, RIGHT };

	EnemyController(Sprite*, GameScore* gs);
	~EnemyController();

	void setupEnemies();
	void resetEnemies();
	void setupBombs(Sprite*);

	void logic(const double delta);
	void enemyBulletCollision(Bullet&);
	void isEnemyOnBottomLayer();
	////
	void bombDropController(const float);
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

	std::vector<Enemy*> bottom_enemies;
	bool readyToDropBomb;

	float last_time;

	std::unique_ptr<Bomb> bomb;
	//std::vector<std::unique_ptr<Bomb>> bombs;

	GameScore* game_score;

};


#endif