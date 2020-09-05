
#include "bullet.h"


Bullet::Bullet(Sprite* s, SDL_Rect start_pos)
	: Entity(s, start_pos),
	bulletActive(false)
{
}

Bullet::~Bullet() {

}



// set the bullet to the rect that is passed in (the player's current position)
void Bullet::fire(SDL_Rect r) {

	bulletActive = true;
	moveTo(r.x + r.w / 2 - bounding_box.w / 2, r.y);
}

bool Bullet::isActive() const {
	return bulletActive;
}

void Bullet::setInactive() {
	reset();
}

void Bullet::setPosition(SDL_Rect pos) {
	bounding_box.x = pos.x;
	bounding_box.y = pos.y;
}

void Bullet::logic(const double delta) {
	if (isActive()) {
		moveBy(0, -100.0 * delta);
	}

	if (util::collisionRectScreenTop(bounding_box, 0)) {
		reset();
	}
}

/// private member functions

void Bullet::reset() {
	bulletActive = false;
	bounding_box.x = bounding_box.y = 0;
}
