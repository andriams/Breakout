#include <Screen/ScreenSDL.h>
#include <Screen/SpriteSDL.h>
#include <iostream>

using namespace breakout;
using namespace std;

ScreenSDL::ScreenSDL()
{
}

void ScreenSDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	m_win = SDL_CreateWindow("BREAKOUT GAME", 100, 100, MAX_WIDTH, MAX_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	m_renderer = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
}

ScreenSDL::~ScreenSDL()
{
	cout << "Destroy window " << endl;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_win);

	SDL_Quit();
}

bool ScreenSDL::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
	SDL_RenderClear(m_renderer);
	return true;
}

bool ScreenSDL::refresh()
{
	SDL_RenderPresent(m_renderer);

	return true;
}

bool ScreenSDL::getDimensions(int &x, int &y) const
{
	x = MAX_WIDTH - 1;
	y = MAX_HEIGHT - 1;
	return true;
}

Action ScreenSDL::getAction()
{
	SDL_Event e;
	static char * prev;

	SDL_PollEvent(&e);

	switch (e.type) {

	case SDL_QUIT:
		return Action::QUIT;
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
			case SDLK_RIGHT: 
				return Action::RIGHT;

			case SDLK_LEFT:
				return Action::LEFT;

			case SDLK_SPACE:
			{
				std::cout << "start" << std::endl;
				return Action::START;
			}

			default:
				return Action::NONE;
		}
		break;
		
	default:
		{
			return Action::NONE;
		}
	}

	return Action::QUIT;
}

bool ScreenSDL::addPixel(const Vec2D<int> &v, char pix, Color c)
{
	return true;
}

