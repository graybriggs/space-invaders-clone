
#pragma once

#ifndef BARRIER_H
#define BARRIER_H

#include "entity.h"

class Barrier : public Entity {
public:

	constexpr static int DIMENSIONS = 64 * 64;

	Barrier(Sprite* sprite, util::Rect pos);




private:

	int getPixel(int x, int y);

private:

	bool body[DIMENSIONS];

};

#endif // !TURRET_H

