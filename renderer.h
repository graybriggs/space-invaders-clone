#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>

class Entity;


void clear_screen(SDL_Renderer* renderer);
void render_entity(SDL_Renderer* renderer, Entity& entity);

#endif