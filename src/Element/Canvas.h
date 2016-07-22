
#pragma once

namespace breakout
{
	class Canvas : public Element {
		public:
			Canvas() : Element(Vec2D<int>(0,0)) {}
			ElementType type() const override { return ElementType::CANVAS; }
	};
}
