

#include "entity.h"

Entity::Entity(const util::rect& r, const std::string& imgPath)
	: boundingBox(r)
{
	//spriteImage = make_unique<SDL_Surface>(SDL_LoadBMP(imgPath.c_str()));

	// reset the returned SDL_Surface pointer to shared_ptr
	// the lambda specifies the surface's free function to call when the
	// shared_ptr's reference count is zero

	spriteImage.reset(SDL_LoadBMP(imgPath.c_str()),
		[=](SDL_Surface* s) {
		SDL_FreeSurface(s);
	});
	// if there was an issue loading the image then throw
	if (spriteImage == nullptr) {
		throw - 1;
	}
	// specify a color key for transparent pixels - here it's 0xFF00FF - bright pink
	Uint32 colorkey = SDL_MapRGB((spriteImage.get())->format, 0xFF, 0x00, 0xFF);
	SDL_SetColorKey(spriteImage.get(), SDL_SRCCOLORKEY, colorkey);
}

Entity::~Entity() {

}

void Entity::moveTo(const double x, const double y) {
	boundingBox.x = x;
	boundingBox.y = y;
}

void Entity::moveBy(const double x, const double y) {
	boundingBox.x += x;
	boundingBox.y += y;
}

util::rect Entity::getBoundingBox() const {
	return boundingBox;
}

void Entity::logic(const double delta) {

}

void Entity::render() const {
	// a copy of an SDL_Rect should be made before submission to
	// SDL_BlitSurface otherwise erroneous behaviour occurs when
	// the rect moves out of window bounds.

	SDL_Rect r;
	rectToSDLRect(boundingBox, r);

	SDL_BlitSurface(spriteImage.get(), NULL, SDL_GetVideoSurface(), &r);
}