#pragma once


#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "utility.h"

#include <SDL.h>
#include <memory>  // for std::unique_ptr
#include <utility> // for std::forward
#include <stdexcept>

class Entity {

public:

	Entity(const util::rect& r, const std::string& imgPath);
	virtual ~Entity();

	void moveTo(const double x, const double y);
	void moveBy(const double x, const double y);
	util::rect getBoundingBox() const;

	virtual void logic(const double delta);
	virtual void render() const;

protected:

	util::rect boundingBox;
	//std::unique_ptr<SDL_Surface> spriteImage;
	std::shared_ptr<SDL_Surface> spriteImage;
};



#endif