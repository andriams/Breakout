
#pragma once

#include <array>
#include <Color/Color.h>
#include <Element/Element.h>
#include <Interface/Obstacle.h>

namespace breakout
{
	class Brick : public Element, private Obstacle {
		public:
			Brick() :Element(Vec2D<int>(0, 0)){}
			Brick(const Vec2D<int> &, Color);

			Color getColor() const override { return m_color; }

			ObstacleResult collision() const override;
			virtual ElementType type() const override { return ElementType::BRICK; }

		private:
			Color m_color;
	};

	class BrickUnbrokable : public Brick {
		public:
			BrickUnbrokable(const Vec2D<int> &);
			BrickUnbrokable() :Brick(){};
			ObstacleResult collision() const override;
			ElementType type() const override { return ElementType::BRICK_UNBROKABLE; }
	};
};
