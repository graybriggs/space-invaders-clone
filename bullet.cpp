
#include "bullet.h"


/*

Bullet::Bullet(const SDL_Rect r, const std::string s)
	: Entity(r, s),
	bulletActive(false)
{
}


// set the bullet to the rect that is passed in (the player's current position)
void Bullet::fire(const SDL_Rect r) {

	if (!isActive()) {
		bulletActive = true;
		boundingBox.x = r.x + r.w / 2 - boundingBox.w / 2;
		boundingBox.y = r.y;
	}
}

bool Bullet::isActive() const {
	return bulletActive;
}

void Bullet::setInactive() {
	reset();
}

void Bullet::logic(const double delta) {
	if (isActive()) {
		moveBy(0, -12.0 * delta);
	}

	if (boundingBox.y + boundingBox.h < 0) {
		reset();
	}
}

void Bullet::render() const {

	if (isActive()) {
		Entity::render();
	}
}

/// private member functions

void Bullet::reset() {
	bulletActive = false;
	boundingBox.x = boundingBox.y = 0;
}

*/