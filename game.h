#pragma once

#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>
#include <memory>

#include "player.h"
#include "enemy.h"
#include "enemy_controller.h"
#include "bullet.h"

class Game {

public:

	Game();

	void initGame();

	void input(SDL_Event event);

	void logic(const double delta);

	void render() const;

private:
	//Player player;
	//EnemyController ec;
	//Bullet* bullet;

};


#endif