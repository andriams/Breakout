
#include <Screen/SpriteSDL.h>
#include <Color/Color.h>
#include <math.h>
#include <iostream>

using namespace breakout;

#define VECT_MOV_BALL Vec2D<double>(0.75, -2) 
#define VECT_POS_BALL  Vec2D<double>(210, 200) 
#define VECT_SIZE_BALL    Vec2D<int>(10, 10) 

#define VECT_POS_RACKET  Vec2D<double>(300, 380) 
#define SIZE_RACKET 40
#define VECT_SIZE_RACKET  Vec2D<int>(SIZE_RACKET, 10)


namespace breakout {

	static Vec2D<double> positionElementToPositionSprite(const Vec2D<int> &v)
	{
		int x,y;
		v.getCoord(x, y);
		return Vec2D<double>(x*40, y*30);
	}
}

/* brique */
SpriteBriqueSDL::SpriteBriqueSDL(Element &b) : 
	Sprite(positionElementToPositionSprite(b.getPosition()),
               Vec2D<int>(30,20), b), m_color(b.getColor()) 
{
}

bool SpriteBriqueSDL::show(Screen &e)
{
	Vec2D<double> position = getPosition();
	double posx, posy;
	position.getCoord(posx, posy);
	
	rect = { posx, posy, 30, 20 };
	if (element().getColor() == Color::WHITE)
		SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 255, 255, 255, 255);
	else
		SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 255, 0, 0, 255);
	SDL_RenderFillRect((SDL_Renderer *)e.renderer(), &rect);
	
	return true;
}

/* racket */
SpriteRacketSDL::SpriteRacketSDL(SpriteObserver &o, Element &r) :
	SpriteRacket(o, VECT_POS_RACKET, VECT_SIZE_RACKET, r) {}

bool SpriteRacketSDL::show(Screen &e)
{
	Vec2D<double> position = getPosition();
	double posx, posy;
	position.getCoord(posx, posy);
	int tx, ty;
	getSize().getCoord(tx, ty);
	rect = { posx, posy, tx, ty };

	SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 0, 255, 255, 255);
	SDL_RenderFillRect((SDL_Renderer *)e.renderer(), &rect);

	return true;
}

/* ball */
SpriteBallSDL::SpriteBallSDL(Element &b) :
	Sprite(VECT_POS_BALL, VECT_SIZE_BALL, b)
{
	setMovement(VECT_MOV_BALL);
}

bool SpriteBallSDL::show(Screen &e)
{
	Vec2D<double> position = getPosition();
	double posx, posy;
	position.getCoord(posx, posy);
	rect = { posx, posy, 10, 10 };

	SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 0, 0, 255, 255);
	SDL_RenderFillRect((SDL_Renderer *)e.renderer(), &rect);

	return true;
}

/* canevas */
SpriteCanvasSDL::SpriteCanvasSDL(Element &c) :
	Sprite(Vec2D<double>(0,0), Vec2D<int>(MAX_WIDTH, MAX_HEIGHT), c) {}

bool SpriteCanvasSDL::show(Screen &e)
{
	rect = { 0, 0, MAX_WIDTH, MAX_HEIGHT };

	SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 0, 0, 0, 255);
	SDL_RenderFillRect((SDL_Renderer *)e.renderer(), &rect);
	return true;
}

bool SpriteSDLFactory::create(Element &e, Sprite **s)
{
	switch (e.type()) {
		case ElementType::BRICK:
		case ElementType::BRICK_UNBROKABLE:
			*s = new SpriteBriqueSDL(e);
			break;
		case ElementType::BALL:
			*s = new SpriteBallSDL(e);
			break;
		case ElementType::CANVAS:
			*s = new SpriteCanvasSDL(e);
			break;
		default:
			return false;
	}

	m_list.push_back(*s);
	return true;
}

bool SpriteSDLFactory::create(SpriteObserver &o, Element &e, SpriteObserved **s)
{
	switch (e.type()) {
		case ElementType::RACKET:
			*s = new SpriteRacketSDL(o, e);
			break;
		default:
			return false;
	}

	m_list.push_back(*s);
	return true;
}
