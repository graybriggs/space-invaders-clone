
#include "entity.h"



Entity::Entity(Sprite* s, const SDL_Rect r)
	: sprite(s),
	  boundingBox(r)
{
	
}

void Entity::moveTo(const double x, const double y) {
	boundingBox.x = static_cast<Sint16>(x);
	boundingBox.y = static_cast<Sint16>(y);
}

void Entity::moveBy(const double x, const double y) {
	boundingBox.x += static_cast<Sint16>(x);
	boundingBox.y += static_cast<Sint16>(y);
}

SDL_Rect Entity::getBoundingBox() const {
	return boundingBox;
}

Sprite* Entity::getSprite() {
	return sprite;
}