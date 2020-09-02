
#include "enemy_bomb.h"

EnemyBomb::EnemyBomb(const util::rect& r, const std::string& s)
	: Entity(util::rect(r), s)
{

}

EnemyBomb::~EnemyBomb() {

}

void EnemyBomb::logic(const double delta) {

	moveBy(0.0, -7.5 * delta);
}

void EnemyBomb::render() {
	Entity::render();
}