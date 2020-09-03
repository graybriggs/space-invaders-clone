
#include "player.h"

Player::Player(Sprite* s, SDL_Rect start_pos)
	: Entity(s, start_pos),
	dir(Direction::STOP),
	fire(false),
	playerScore(0)
{
}

Player::~Player() {

}

void Player::input(SDL_Event event) {

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			dir = Direction::LEFT;
			break;
		case SDLK_RIGHT:
			dir = Direction::RIGHT;
			break;
		case SDLK_SPACE:
			fire = true;
		default:
			break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			dir = Direction::STOP;
			break;
		case SDLK_RIGHT:
			dir = Direction::STOP;
			break;
		case SDLK_SPACE:
			fire = false;
		default:
			break;
		}
	}
}

void Player::logic(double delta) {

	if (util::collisionRectScreenLeft(boundingBox, 0)) {
		dir = Direction::STOP;
		moveBy(delta, 0.0);
	}
	else if (util::collisionRectScreenRight(boundingBox, 1024)) {
		dir = Direction::STOP;
		moveBy(-delta, 0.0);
	}

	if (dir == Direction::LEFT) {
		moveBy(-5.0 * delta, 0.0);
	}
	else if (dir == Direction::RIGHT) {
		moveBy(5.0 * delta, 0.0);
	}

}


bool Player::fireBullet() {
	return fire;
}

void Player::incrementScore(int enemyValue) {

	playerScore += enemyValue;
	std::cout << playerScore << std::endl;
}
