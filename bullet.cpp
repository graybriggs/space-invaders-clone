
#include "bullet.h"


Bullet::Bullet(Sprite* s, util::Rect start_pos)
	: Entity(s, start_pos),
	bulletActive(false)
{
}

Bullet::~Bullet() {

}


// set the bullet to the rect that is passed in (the player's current position)
void Bullet::fire(util::Rect r) {

	bulletActive = true;
	moveTo(r.pos_x + r.w / 2 - bounding_box.w / 2, r.pos_y);
}

bool Bullet::isActive() const {
	return bulletActive;
}

void Bullet::setInactive() {
	reset();
}

void Bullet::setPosition(util::Rect pos) {
	bounding_box.pos_x = pos.pos_x;
	bounding_box.pos_y = pos.pos_y;
}

void Bullet::logic(const double delta) {
	if (isActive()) {
		moveBy(0, -60.0 * delta);
	}

	if (util::collisionRectScreenTop(bounding_box, 0)) {
		reset();
	}
}

/// private member functions

void Bullet::reset() {
	bulletActive = false;
	bounding_box.pos_x = bounding_box.pos_y = 0;
}
