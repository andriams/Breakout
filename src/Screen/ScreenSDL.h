#pragma once

#include <SDL.h>
#include <Ecran/Ecran.h>
#include <Vecteur/Vecteur.h>
#include <Couleur/Couleur.h>
//#include <Ecran/SpriteSDL.h>

namespace cassebrique {

#define MAX_WIDTH 640
#define MAX_HEIGHT 480

	enum EcranCouleur : short int { COULEUR_AUCUNE, COULEUR_BLANC, COULEUR_BLEU, COULEUR_ROUGE };

	class EcranSDL : public Ecran {
	public:
		EcranSDL();
		~EcranSDL();
		void init() override;
		bool effacer() override;
		bool rafraichir() override;
		Action lireAction() override;
		bool recupererDimensions(int &x, int &y) const override;
		bool ajouterPixel(const Vecteur<int> &v, char pix, Couleur c) override;
		void *renderer() override { return m_renderer; }
	private:
		SDL_Window *m_win;
		SDL_Renderer *m_renderer;
	};
};
