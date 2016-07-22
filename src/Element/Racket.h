
#pragma once

#include <Element/Element.h>

namespace breakout
{
	class Racket : public Element {
		public:
			Racket() : Element(Vec2D<int>(10, 10)) {}
			Racket(const Vec2D<int> &v) : Element(v) {}
			ElementType type() const override { return ElementType::RACKET; }

	};

};
