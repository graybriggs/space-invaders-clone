
#include "entity.h"



Entity::Entity(Sprite* s, const SDL_Rect r)
	: sprite(s),
	  bounding_box(r)
{
	
}

void Entity::moveTo(const double x, const double y) {
	bounding_box.x = static_cast<Sint16>(x);
	bounding_box.y = static_cast<Sint16>(y);
}

void Entity::moveBy(const double x, const double y) {
	bounding_box.x += static_cast<Sint16>(x);
	bounding_box.y += static_cast<Sint16>(y);
}

SDL_Rect Entity::getBoundingBox() const {
	return bounding_box;
}

Sprite* Entity::getSprite() {
	return sprite;
}