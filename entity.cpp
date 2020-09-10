
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
}

void Entity::setPosition(const double x, const double y) {
	moveTo(x, y);
}

void Entity::setPosition(const SDL_Rect r) {
	bounding_box.pos_x = r.x;
	bounding_box.pos_y = r.y;
}

void Entity::setPosition(const util::Rect r) {
	bounding_box.pos_x = r.pos_x;
	bounding_box.pos_y = r.pos_y;
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

void Entity::setImageClipBox(std::initializer_list<int> pos) {

	auto p = std::begin(pos);

	SDL_Rect r;
	r.x = *p;
	r.y = *(p+1);
	r.w = *(p+2);
	r.h = *(p+3);
	setImageClipBox(r);
}