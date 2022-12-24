#include "entity.h"
#include "particle.h"
#include "renderer.h"

void clear_screen(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
	SDL_RenderClear(renderer);
}

void render_entity(SDL_Renderer* renderer, const Entity& entity) {
	
	SDL_Rect bounding_box = entity.getBoundingBox().getSDLRect();

	SDL_Rect r = entity.getImageClipBox();

	SDL_RenderCopy(renderer,
		entity.getSprite()->getTexture(),
		&r,
		&(bounding_box)
	);
}

void render_surface(SDL_Renderer* renderer, const Entity& entity,SDL_Surface* surface) {
	SDL_Rect bounding_box = entity.getBoundingBox().getSDLRect();

	SDL_Texture* updated_tex = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_Rect r = entity.getImageClipBox();

	SDL_RenderCopy(renderer, updated_tex, &r, &bounding_box);
}

void render_rect(SDL_Renderer* renderer, const SDL_Rect rect, const SDL_Color color) {

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(renderer, &rect);
}

///////////

void render_particles(SDL_Renderer* renderer, std::vector<Particle>& particles) {
	for (auto& p : particles) {
		if (p.is_alive()) {
			SDL_Rect r = p.get_box();
			//SDL_RenderDrawRect(rend, &r); // SDL_RenderFillRect  ????
			////
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xE8, 0x7C, 0x00);  // color code: "sun yellow"
			SDL_RenderFillRect(renderer, &r);
		}
	}
}