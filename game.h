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

	static const int SCREEN_W;
	static const int SCREEN_H;
	static const int SCREEN_BPP;

	Game();

	void initGame();

	void input(SDL_Event event);

	void logic(const double delta);

	void render() const;

private:
	Player player;
	EnemyController ec;
	std::shared_ptr<Bullet> bullet;

};


#endif