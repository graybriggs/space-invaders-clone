#pragma once

#include "counter.h"
#include "enemy.h"
#include "game_score.h"

class BonusEnemy : public Enemy {
public:
	BonusEnemy() = delete;
	BonusEnemy(Sprite* s, util::Rect pos);
	void active(bool toggle);
	virtual ~BonusEnemy();

private:
	bool is_active;
};

// Bonus enemy appears every 20 seconds and scrolls from top right to
// top left of the screen dropping bombs at regular intervals
// The bombs it drops can destroy other enemies.

//class Counter;

class BonusEnemyController {
public:
	BonusEnemyController(BonusEnemy* e, GameScore* gs);

	void move(double delta);
	void logic(double delta);
	void render_bonus_enemy(SDL_Renderer* renderer);

private:
	//Counter bonus_enemy_timer;
	BonusEnemy* bonus_enemy;
	bool active;

	GameScore* game_score;
};