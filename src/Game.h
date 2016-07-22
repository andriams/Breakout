#pragma once

#include <Strat/Level.h>
#include <Screen/Screen.h>
#include <Physic/Physic2D.h>
#include <Screen/SpriteSDL.h> 
#include <Geom/Vec2D.h>
#include <Movement/Movement.h>

namespace breakout {

	class Game {
		public:
			Game(Screen &screen, Physic2D &physic) : m_screen(screen), m_physic(physic), m_pending(false) {}
			bool start(Level &level);
			bool show();

			bool execute(Action action);
		private:
			bool collision(Sprite *rencontre);

			Ball m_ball;
			Canvas m_canvas;
			Racket m_racket;

			Sprite *m_sprite_ball;
			Sprite *m_sprite_canvas;
			SpriteRacket *m_sprite_racket;
			std::list<Sprite*> m_sprites;

			Screen &m_screen;
			Physic2D &m_physic;

			Level *m_level;
			SpriteSDLFactory m_sprite_factory; 
			bool m_pending;
	};
}
