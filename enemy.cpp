
#include "enemy.h"
#include "utility.h"

Enemy::Enemy(Sprite* s, util::Rect pos)
	: Entity(s,pos)
{
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