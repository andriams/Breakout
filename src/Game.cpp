
#include <Game.h>
#include <math.h>

using namespace breakout;

bool Game::start(Level &level)
{
	int x, y;

	m_screen.init();
	m_screen.getDimensions(x, y);

	/* creation of canvas */
	if (m_sprite_factory.create(m_canvas, &m_sprite_canvas) != true) {
		return false;
	}
	m_physic.canvas(m_sprite_canvas, 1, 1, x, y);

	/* create bricks */
	for (Element *it : level) {
		Element &b = *it;
		Sprite *s;
		if (m_sprite_factory.create(b, &s) == false) {
			return false;
		}
		m_sprites.push_back(s);
		m_physic.add(*s);
	}

	/* create racket */
	if (m_sprite_factory.create(m_physic, m_racket, (SpriteObserved **)&m_sprite_racket) != true) {
		return false;
	}
	m_physic.add(*m_sprite_racket);

	/* create ball */
	if (m_sprite_factory.create(m_ball, &m_sprite_ball) != true) {
		return false;
	}

	m_level = &level;

	return true;
}

bool Game::collision(Sprite *meet)
{
	switch (meet->element().collision()) {
		case ObstacleResult::UNBROKEN:
			return false;

		case ObstacleResult::BROKEN:
			m_sprites.remove(meet); 
			m_physic.del(*meet); 
			m_level->del(meet->element());
			return true;
	}
	return false;
}

bool Game::show()
{
	m_screen.clear();

	m_sprite_canvas->show(m_screen);
	for (Sprite *s : m_sprites) {
		s->show(m_screen);
	}

	m_sprite_ball->show(m_screen);
	m_sprite_racket->show(m_screen);
	
	m_screen.refresh();

	return true;
}

bool Game::execute(Action action)
{
	std::list<Sprite*> collisions;
	Vec2D<double> movement;

	switch (action) {
		case Action::RIGHT:
			m_sprite_racket->setMovement(Vec2D<double>(5,0));
			movement = moveSprite(m_physic, m_sprite_racket, collisions);
			m_sprite_racket->setMovement(movement);
			break;
		case Action::LEFT:
			m_sprite_racket->setMovement(Vec2D<double>(-5, 0));
			movement = moveSprite(m_physic, m_sprite_racket, collisions);
			m_sprite_racket->setMovement(movement);
			break;

		case Action::START:
			m_pending = true;
			break;

		case Action::QUIT:
			return false;

		case Action::NONE:
			break;
	}

	/* move ball at each iteration */
	if (m_pending) {
		//std::cout << "pending" << std::endl;
		int ex, ey, bx, by, dimx, dimy;
		m_screen.getDimensions(ex, ey);

		Vec2D<double> movement = moveSprite(m_physic, m_sprite_ball, collisions);
		m_sprite_ball->setMovement(movement);

		/* check ball is out */
		Vec2DDoubleToInt(m_sprite_ball->getPosition()).getCoord(bx, by);
		m_sprite_ball->getSize().getCoord(dimx, dimy);
		if (by == ey - dimy - 1) {
			return false;
		}

		if (collisions.size()) {
			/* collision */
			for (auto sprite : collisions) {
				collision(sprite);
			}

			if (m_level->isEnding() == true) {
				return false;
			}
		}
	}

	return true;
}
