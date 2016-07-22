
#pragma once

#include <Element/Element.h>

namespace breakout
{
	class Ball : public Element {
		public:
			Ball() : Element(Vec2D<int>(10, 9)) {}
			Ball(const Vec2D<int> &v) : Element(v) {}
			ElementType type() const override { return ElementType::BALL; }

	};

};
