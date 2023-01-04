
#include "barrier.h"

Barrier::Barrier(Sprite* sprite, util::Rect pos)
	: Entity(sprite, pos) {


}

int Barrier::getPixel(int x, int y) {
	return DIMENSIONS / 2 * y + x;
}