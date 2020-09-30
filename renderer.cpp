#include "entity.h"
#include "renderer.h"

void clear_screen(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
	SDL_RenderClear(renderer);
}

void render_entity(SDL_Renderer* renderer, const Entity& entity) {
	
	SDL_Rect bounding_box = entity.getBoundingBox().getSDLRect();

	SDL_RenderCopy(renderer,
		entity.getSprite()->getTexture(),
		&(entity.getImageClipBox()),
		&(bounding_box)
	);
}

void render_surface(SDL_Renderer* renderer, const Entity& entity,SDL_Surface* surface) {
	SDL_Rect bounding_box = entity.getBoundingBox().getSDLRect();

	SDL_Texture* updated_tex = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_RenderCopy(renderer, updated_tex, &(entity.getImageClipBox()), &bounding_box);
}

void render_rect(SDL_Renderer* renderer, const SDL_Rect rect) {

	SDL_RenderDrawRect(renderer, &rect);
}