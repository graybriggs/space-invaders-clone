
#pragma once

#include "bonus_enemy.h"
#include "entity.h"
#include "globals.h"
#include "renderer.h"
#include "counter.h"

BonusEnemy::BonusEnemy(Sprite* s, util::Rect pos) :
		Enemy(s, pos)
{
		setAlive();
}

BonusEnemy::~BonusEnemy() {};

void BonusEnemy::active(bool toggle) {
	is_active = toggle;
}

// Bonus enemy appears every 20 seconds and scrolls from top right to
// top left of the screen dropping bombs at regular intervals
// The bombs it drops can destroy other enemies.

BonusEnemyController::BonusEnemyController(BonusEnemy* e, GameScore* gs) :
		bonus_enemy(e),
		bonus_enemy_timer(3000),
		active(false),
		game_score(gs)
	{
	}


void BonusEnemyController::move(double delta) {
	if (util::collisionRectScreenLeft(bonus_enemy->getBoundingBox(), 0)) {
		//dir = Direction::STOP;
		active = false;
		bonus_enemy->moveTo(global::SCREEN_W, global::SCREEN_H - 600);
		bonus_enemy_timer.reset();
	}
	bonus_enemy->moveBy(-5.0 * delta, 0.0);
}

void BonusEnemyController::logic(double delta) {
	bonus_enemy_timer.update();
	if (active) {
		move(delta);
	}
}

void BonusEnemyController::render_bonus_enemy(SDL_Renderer* renderer) {
	if (active) {
		render_entity(renderer, *bonus_enemy);
	}
}