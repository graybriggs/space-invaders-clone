#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>

class Entity;


void clear_screen(SDL_Renderer* renderer);
void render_entity(SDL_Renderer* renderer, const Entity& entity);
void render_rect(SDL_Renderer* renderer, SDL_Rect rect);

#endif