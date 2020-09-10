#pragma once

#include <vector>

class Enemy;

class BombController {
public:

	void logic(const double delta);
	void renderBombs();

	void bombDrop(std::vector<Enemy>& bottom_enemies);

private:

	double enemy_speed;

};