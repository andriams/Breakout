#pragma once

#include <Geom/Vec2D.h>
#include <Interface/Obstacle.h>
#include <Color/Color.h>

namespace breakout
{

	enum class ElementType { ELEMENT, CANVAS, BRICK, BRICK_UNBROKABLE, RACKET, BALL };

	class Element {
		public:
			Element(const Vec2D<int> &p);

			void setPosition(const Vec2D<int> &p);
			Vec2D<int> getPosition(void) const;

			/* interface Obstacle */
			virtual ObstacleResult collision() const { return ObstacleResult::UNBROKEN; }

			virtual Color getColor() const { return Color::WHITE; }
			virtual ElementType type() const { return ElementType::ELEMENT; }

		private: 
			Vec2D<int> m_position;
	};
};
