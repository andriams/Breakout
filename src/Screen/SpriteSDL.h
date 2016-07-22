
#pragma once

#include <list>
#include <Screen/Sprite.h>
#include <Screen/ScreenSDL.h>

namespace breakout {

	class SpriteBriqueSDL : public Sprite {
		public:
			SpriteBriqueSDL(Element &b);
			bool show(Screen &)override;
		private:
			const Color m_color;
			SDL_Rect rect;
	};

	class SpriteBallSDL : public Sprite {
		public:
			SpriteBallSDL(Element &b);
			bool show(Screen &) override;
		private:
			SDL_Rect rect;
	};

	class SpriteCanvasSDL : public Sprite {
		public:
			SpriteCanvasSDL(Element &c);
			bool show(Screen &) override;
		private:
			SDL_Rect rect;
	};

	/* the racket is oberved */
	class SpriteRacketSDL : public SpriteRacket {
		public:
			SpriteRacketSDL(SpriteObserver &o, Element &r);
			bool show(Screen &) override;
		private:
			SDL_Rect rect;
	};

	class SpriteSDLFactory {
		public:
			SpriteSDLFactory() { m_list.clear(); }
			~SpriteSDLFactory() {
				for (Sprite *s : m_list) { delete s; } m_list.clear();
			}

			bool create(Element &e, Sprite **s);
			bool create(SpriteObserver &o, Element &e, SpriteObserved **s);
			bool destroy(Sprite *s) { m_list.remove(s); delete s; return true; }

		private:
			std::list<Sprite*> m_list;
	};

}
