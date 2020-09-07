
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
void Enemy::dropBomb() {

}

void Enemy::logic(const double delta, bool b) {
	SDL_Rect r;
	if (!b) {
		r = util::prepare_rect(0, 0, 32, 32);
		setImageClipBox(r);
	}
	else {
		r = util::prepare_rect(64, 0, 32, 32);
		setImageClipBox(r);
	}
}