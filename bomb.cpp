
#include "bomb.h"
#include "globals.h"

Bomb::Bomb(Sprite* sprite, util::Rect pos)
	: Entity(sprite, pos) {}

Bomb::~Bomb() {}

void Bomb::bombDropped(const double x, const double y) {

	setPosition(x, y);
}

void Bomb::setActive() {
	active = true;
}

bool Bomb::isActive() const {
	return active;
}

void Bomb::logic(const double delta) {

	if (active) {
		moveBy(0, 2.5 * delta);
	}

	if (util::collisionRectScreenBottom(bounding_box, global::SCREEN_H)) {
		active = false;
	}
}