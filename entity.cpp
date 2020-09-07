
#include "entity.h"

Entity::Entity(Sprite* s, const util::Rect r)
	: sprite(s),
	  bounding_box(r)
{	
}

void Entity::moveTo(const double x, const double y) {
	bounding_box.pos_x = x;
	bounding_box.pos_y = y;
}

void Entity::moveBy(const double x, const double y) {

	bounding_box.pos_x += x;
	bounding_box.pos_y += y;

	//bounding_box.x += static_cast<Sint16>(x);
	//bounding_box.y += static_cast<Sint16>(y);
}

util::Rect Entity::getBoundingBox() const {
	return bounding_box;
}

Sprite* Entity::getSprite() {
	return sprite;
}

SDL_Rect Entity::getImageClipBox() const {
	return image_clip_box;
}


void Entity::setImageClipBox(SDL_Rect box) {
	image_clip_box = box;
}