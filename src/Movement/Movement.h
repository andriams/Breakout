
#pragma once

#include <Geom/Vec2D.h>
#include <Screen/Sprite.h>
#include <Physic/Physic2D.h>

namespace breakout {

template <typename P>
bool testMovement(const P &physic, Sprite *sprite, Vec2D<double> movement, Sprite **meet)
{
	/* test collision */
	Vec2D<double> position  = sprite->getPosition();

	Vec2D<int> next_position = Vec2DDoubleToInt(position + movement);

	if (physic.collision(*sprite, next_position, meet) == false) {
		return false;
	}

	/* collision */
	return true;
}

template <typename P, typename S>
Vec2D<double> moveSprite(const P &physic, S *sprite, std::list<Sprite*> &collisions)
{
	S *meet;
	Vec2D<double> spriteMovement = sprite->getMovement();

	/* collision : inverse movement */
	double mv_x, mv_y;
	spriteMovement.getCoord(mv_x, mv_y);

	/* test on X */
	Vec2D<double> movement = Vec2D<double>(mv_x, 0);
	if (testMovement(physic, sprite, movement, &meet) == false) {
		sprite->move(movement);
	} else {
		mv_x = -mv_x;
		collisions.push_back(meet);
	}

	/* test on  Y */
	movement = Vec2D<double>(0, mv_y);
	if (testMovement(physic, sprite, movement, &meet) == false) {
		sprite->move(movement);
	} else {
		mv_y = -mv_y;
		collisions.push_back(meet);
	}

	return Vec2D<double>(mv_x, mv_y);
}

template <typename P>
Vec2D<double> moveSprite(const P &physic, SpriteRacket *sprite, std::list<Sprite*> &collisions)
{
	Sprite *meet;
	if (testMovement(physic, sprite, sprite->getMovement(), &meet) == false) {
		sprite->move(sprite->getMovement());
	}
	return Vec2D<double>(0,0);
}

};
