#pragma once

#include <Element/Brick.h>
#include <Element/Ball.h>
#include <Element/Racket.h>
#include <Element/Canvas.h>

#include <Color/Color.h>

namespace breakout {

	enum class Action { RIGHT, LEFT, QUIT, START, NONE };
	
	class Screen {
	public:
		Screen() {};
		virtual ~Screen() {};
		virtual bool clear() = 0;
		virtual void init() = 0;
		virtual bool refresh() = 0;
		virtual Action getAction() = 0;
		virtual bool getDimensions(int &x, int &y) const = 0;
		virtual bool addPixel(const Vec2D<int> &v, char pix, Color c) = 0;
		virtual void* renderer() = 0;
	};
};
