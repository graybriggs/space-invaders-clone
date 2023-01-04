
#include "globals.h"
#include "player.h"

Player::Player(Sprite* s, util::Rect start_pos)
	: Entity(s, start_pos),
	dir(Direction::STOP),
	canFire(true),
	fire(false),
	playerScore(0)
{
	setImageClipBox(util::prepare_rect(0,0,32,16));
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
			break;
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
			//fire = false;
			break;
		default:
			break;
		}
	}
}

void Player::logic(double delta) {

	if (util::collisionRectScreenLeft(bounding_box, 0)) {
		//dir = Direction::STOP;
		moveTo(0, global::SCREEN_H - 100);
	}
	else if (util::collisionRectScreenRight(bounding_box, global::SCREEN_W)) {
		//dir = Direction::STOP;
		moveTo(global::SCREEN_W - 32, global::SCREEN_H - 100);
	}

	if (dir == Direction::LEFT) {
		moveBy(-5.0 * delta, 0.0);
	}
	else if (dir == Direction::RIGHT) {
		moveBy(5.0 * delta, 0.0);
	}
}

bool Player::hasFired() const {
	return fire;
}

void Player::fireWait() {
	fire = false;
}

void Player::canFireOK() {
	canFire = true;
}

void Player::incrementScore(int enemyValue) {

	playerScore += enemyValue;
	std::cout << playerScore << std::endl;
}
