#include <stdexcept>
#include <utility>

#include "sprite.h"


int load_spritesheet(SDL_Renderer* renderer, SDL_Texture** spritesheet, std::string img_path) {

	SDL_Surface* surface_img = SDL_LoadBMP(img_path.c_str());
	if (surface_img == nullptr) {
		fprintf(stderr, "Error loading image file");
		throw - 1;
	}

	// specify a color key for transparent pixels - here it's 0xFF00FF - bright pink
	Uint32 colorkey = SDL_MapRGB(surface_img->format, 0xFF, 0x00, 0xFF);
	SDL_SetColorKey(surface_img, SDL_TRUE, colorkey);

	*spritesheet = SDL_CreateTextureFromSurface(renderer, surface_img);
	SDL_FreeSurface(surface_img);

	if (spritesheet == nullptr) {
		throw - 1;
	}
	return 0;
}

std::unique_ptr<Sprite> load_sprite(SDL_Renderer* renderer, std::string path) {

	SDL_Texture* tex;
	load_spritesheet(renderer, &tex, path);
	auto sprite = std::make_unique<Sprite>(tex);
	return std::move(sprite);
}


Sprite::Sprite(SDL_Texture* spritesheet)
	: texture(spritesheet)
{
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}


SDL_Texture* Sprite::getTexture() const {
	return texture;
}

void Sprite::setTexture(SDL_Texture* tex) {
	texture = tex;
}
