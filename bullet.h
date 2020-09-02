#pragma once

#ifndef BULLET_HPP
#define BULLET_HPP

#include "entity.h"
#include "utility.h"
#include <string>
#include <iostream>

class Bullet : public Entity {

public:

	Bullet(const util::rect& r, const std::string& s);
	virtual ~Bullet() {}

	void fire(const util::rect& r);
	bool isActive() const;
	void setInactive();

	void logic(const double delta);
	void render() const;

private:
	void reset();

	bool bulletActive;
};

#endif