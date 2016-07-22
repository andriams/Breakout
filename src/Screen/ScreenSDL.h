#pragma once

#include <SDL.h>
#include <Screen/Screen.h>
#include <Geom/Vec2D.h>
#include <Color/Color.h>

namespace breakout {

#define MAX_WIDTH 640
#define MAX_HEIGHT 480

	enum ScreenColor : short int { COLOR_NONE, COLOR_WHITE, COLOR_BLUE, COLOR_RED };

	class ScreenSDL : public Screen {
	public:
		ScreenSDL();
		~ScreenSDL();
		void init() override;
		bool clear() override;
		bool refresh() override;
		Action getAction() override;
		bool getDimensions(int &x, int &y) const override;
		bool addPixel(const Vec2D<int> &v, char pix, Color c) override;
		void *renderer() override { return m_renderer; }
	private:
		SDL_Window *m_win;
		SDL_Renderer *m_renderer;
	};
};
