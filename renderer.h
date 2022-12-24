#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>

#include <vector>

class Entity;
class Particle;

void clear_screen(SDL_Renderer* renderer);
void render_entity(SDL_Renderer* renderer, const Entity& entity);
void render_surface(SDL_Renderer* renderer, const Entity& entity, SDL_Surface* surface);
void render_rect(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color color);

////////

void render_particles(SDL_Renderer* renderer, std::vector<Particle>& particles);

#endif