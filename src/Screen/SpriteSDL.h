
#pragma once

#include <list>
#include <Ecran/Sprite.h>
#include <Ecran/EcranSDL.h>

namespace cassebrique {

	class SpriteBriqueSDL : public Sprite {
		public:
			SpriteBriqueSDL(Element &b);
			bool afficher(Ecran &)override;
		private:
			const Couleur m_couleur;
			SDL_Rect rect;
	};

	class SpriteBalleSDL : public Sprite {
		public:
			SpriteBalleSDL(Element &b);
			bool afficher(Ecran &) override;
		private:
			SDL_Rect rect;
	};

	class SpriteCanevasSDL : public Sprite {
		public:
			SpriteCanevasSDL(Element &c);
			bool afficher(Ecran &) override;
		private:
			SDL_Rect rect;
	};

	/* la raquette est observée */
	class SpriteRaquetteSDL : public SpriteRaquette {
		public:
			SpriteRaquetteSDL(SpriteObservateur &o, Element &r);
			bool afficher(Ecran &) override;
		private:
			SDL_Rect rect;
	};

	/* pourrait etre un singleton et une classe générique SpriteFactory */
	class SpriteSDLFactory {
		public:
			SpriteSDLFactory() { m_list.clear(); }
			~SpriteSDLFactory() {
				for (Sprite *s : m_list) { delete s; } m_list.clear();
			}

			bool creer(Element &e, Sprite **s);
			bool creer(SpriteObservateur &o, Element &e, SpriteObserve **s);
			bool detruire(Sprite *s) { m_list.remove(s); delete s; return true; }

		private:
			std::list<Sprite*> m_list;
	};

}
