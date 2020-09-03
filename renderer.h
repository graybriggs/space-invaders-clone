#pragma once

#include <SDL.h>

#include "entity.h"

void clear_screen(SDL_Renderer* renderer);
void render_entity(SDL_Renderer* renderer, Entity& entity);