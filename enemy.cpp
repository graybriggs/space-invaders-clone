
#include "enemy.h"

Enemy::Enemy(Sprite* s, SDL_Rect pos)
	: Entity(s,pos)
{
}

Enemy::~Enemy() {}

void Enemy::setDead() {}
void Enemy::setAlive() {}
bool Enemy::isDead() const {
	return false;
}
void Enemy::setCanDropBombs(bool b) {
}

int Enemy::getValue() {
	return -1;
}

bool Enemy::canEnemyDropBomb() {
	return false;
}
//
void Enemy::dropBomb() {}
//
void Enemy::logic(const double delta) {}