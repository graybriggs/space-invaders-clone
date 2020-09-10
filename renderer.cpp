#include "entity.h"
#include "renderer.h"

void clear_screen(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
	SDL_RenderClear(renderer);
}

void render_entity(SDL_Renderer* renderer, Entity& entity) {
	
	SDL_Rect bounding_box = entity.getBoundingBox().getSDLRect();

	SDL_RenderCopy(renderer,
		entity.getSprite()->getTexture(),
		//&(entity.getSprite()->getClipBox()),
		&(entity.getImageClipBox()),
		&(bounding_box)
	);
}
