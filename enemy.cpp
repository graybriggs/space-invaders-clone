
#include "enemy.h"
#include "utility.h"

Enemy::Enemy(Sprite* s, util::Rect pos)
	: Entity(s,pos)
{
	canDropBomb = false;
}

Enemy::~Enemy() {}

void Enemy::setDead() {
	dead = true;
}

void Enemy::setAlive() {
	dead = false;
}

bool Enemy::isDead() const {
	return dead;
}

void Enemy::setCanDropBombs(bool b) {
	canDropBomb = b;
}


bool Enemy::canDropBombs() {
	return canDropBomb;
}
//
void Enemy::dropBomb() {}
//
void Enemy::logic(const double delta) {

	if (canDropBomb) {
		SDL_Rect r;
		r.x = 32;
		r.y = 0;
		r.w = 32;
		r.h = 32;
		sprite->setClipBox(r);
	}
	else {
		SDL_Rect r;
		r.x = 0;
		r.y = 0;
		r.w = 32;
		r.h = 32;
		sprite->setClipBox(r);
	}
}