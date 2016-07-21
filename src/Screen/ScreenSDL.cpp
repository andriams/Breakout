#include <Ecran/EcranSDL.h>
#include <Ecran/SpriteSDL.h>
#include <iostream>

using namespace cassebrique;
using namespace std;

EcranSDL::EcranSDL()
{
	cout << "Affichage ecran" << endl;
}

void EcranSDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	m_win = SDL_CreateWindow("Cassebrique_SDL", 100, 100, MAX_WIDTH, MAX_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	m_renderer = SDL_CreateRenderer(m_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
}

EcranSDL::~EcranSDL()
{
	cout << "Destroy window " << endl;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_win);

	SDL_Quit();
}

bool EcranSDL::effacer()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
	SDL_RenderClear(m_renderer);
	return true;
}

bool EcranSDL::rafraichir()
{
	SDL_RenderPresent(m_renderer);

	return true;
}

bool EcranSDL::recupererDimensions(int &x, int &y) const
{
	/* getmaxyx(stdscr, x, y);*/
	x = MAX_WIDTH - 1;
	y = MAX_HEIGHT - 1;
	return true;
}

Action EcranSDL::lireAction()
{
	/* on boucle jusqu'au timeout du select */
	SDL_Event e;
	static char * prev;

	SDL_PollEvent(&e);

	/* on execute l'action qu'on a trouvé pendant la période */
	switch (e.type) {

	case SDL_QUIT:
		return Action::QUITTER;
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
			case SDLK_RIGHT: // Flèche droite
				return Action::DROITE;

			case SDLK_LEFT: // Flèche gauche
				return Action::GAUCHE;

			case SDLK_SPACE: // demarrer
				return Action::DEMARRER;

			default:
				return Action::AUCUNE;
		}
		break;
		
	default:
		{
			return Action::AUCUNE;
		/* rien pour l'instant */
		}

	}


	return Action::QUITTER;
}

bool EcranSDL::ajouterPixel(const Vecteur<int> &v, char pix, Couleur c)
{
	return true;
}

