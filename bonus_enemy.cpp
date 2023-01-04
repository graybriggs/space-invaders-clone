
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
		//bonus_enemy_timer(3000),
		active(true),
		game_score(gs)
	{
	}


void BonusEnemyController::move(double delta) {
	util::Rect r = bonus_enemy->getBoundingBox();
	r.pos_x += r.w; // so the entire image dissapears off screen

	if (util::collisionRectScreenLeft(r, 0)) {
		//dir = Direction::STOP;
		active = true;
		bonus_enemy->moveTo(global::SCREEN_W, global::SCREEN_H - 650);
		//bonus_enemy_timer.reset();
	}
	bonus_enemy->moveBy(-0.8 * delta, 0.0);
}

void BonusEnemyController::logic(double delta) {
	//bonus_enemy_timer.update();
	if (active) {
		move(delta);
	}
}

void BonusEnemyController::render_bonus_enemy(SDL_Renderer* renderer) {
	if (active) {
		render_entity(renderer, *bonus_enemy);
	}
}