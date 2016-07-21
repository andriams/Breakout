
#include <Ecran/SpriteSDL.h>
#include <Couleur/Couleur.h>
#include <math.h>
#include <iostream>

using namespace cassebrique;

#define VECTEUR_MOUVEMENT_BALLE Vecteur<double>(-1.5, -4) // deplacement en cases par 1/24e de secondes
#define VECTEUR_POSITION_BALLE  Vecteur<double>(210, 200) // deplacement en cases par 1/24e de secondes
#define VECTEUR_TAILLE_BALLE    Vecteur<int>(10, 10) // deplacement en cases par 1/24e de secondes

#define VECTEUR_POSITION_RAQUETTE  Vecteur<double>(300, 380) // deplacement en cases par 1/24e de secondes
#define TAILLE_RAQUETTE 40
#define VECTEUR_TAILLE_RAQUETTE  Vecteur<int>(TAILLE_RAQUETTE, 10) // deplacement en cases par 1/24e de secondes


namespace cassebrique {

	static Vecteur<double> positionElementVersPositionSprite(const Vecteur<int> &v)
	{
		int x,y;
		v.recupererCoordonnees(x, y);
		return Vecteur<double>(x*40, y*30);
	}
}

/* brique */
SpriteBriqueSDL::SpriteBriqueSDL(Element &b) : 
	Sprite(positionElementVersPositionSprite(b.recupererPosition()),
               Vecteur<int>(30,20), b), m_couleur(b.recupererCouleur()) 
{
}

bool SpriteBriqueSDL::afficher(Ecran &e)
{
	Vecteur<double> position = recupererPosition();
	double posx, posy;
	position.recupererCoordonnees(posx, posy);
	
	rect = { posx, posy, 30, 20 };
	if (element().recupererCouleur() == Couleur::BLANC)
		SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 255, 255, 255, 255);
	else
		SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 255, 0, 0, 255);
	SDL_RenderFillRect((SDL_Renderer *)e.renderer(), &rect);
	
	return true;
}

/* raquette */
SpriteRaquetteSDL::SpriteRaquetteSDL(SpriteObservateur &o, Element &r) :
	SpriteRaquette(o, VECTEUR_POSITION_RAQUETTE, VECTEUR_TAILLE_RAQUETTE, r) {}

bool SpriteRaquetteSDL::afficher(Ecran &e)
{
	Vecteur<double> position = recupererPosition();
	double posx, posy;
	position.recupererCoordonnees(posx, posy);
	int tx, ty;
	recupererTaille().recupererCoordonnees(tx, ty);
	rect = { posx, posy, tx, ty };

	SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 0, 255, 255, 255);
	SDL_RenderFillRect((SDL_Renderer *)e.renderer(), &rect);

	return true;
}

/* balle */
SpriteBalleSDL::SpriteBalleSDL(Element &b) :
	Sprite(VECTEUR_POSITION_BALLE, VECTEUR_TAILLE_BALLE, b)
{
	nouveauMouvement(VECTEUR_MOUVEMENT_BALLE);
}

bool SpriteBalleSDL::afficher(Ecran &e)
{
	Vecteur<double> position = recupererPosition();
	double posx, posy;
	position.recupererCoordonnees(posx, posy);
	rect = { posx, posy, 10, 10 };

	SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 0, 0, 255, 255);
	SDL_RenderFillRect((SDL_Renderer *)e.renderer(), &rect);

	return true;
}

/* canevas */
SpriteCanevasSDL::SpriteCanevasSDL(Element &c) :
	Sprite(Vecteur<double>(0,0), Vecteur<int>(MAX_WIDTH-1, MAX_HEIGHT-1), c) {}

bool SpriteCanevasSDL::afficher(Ecran &e)
{
	rect = { 0, 0, MAX_WIDTH-1, MAX_HEIGHT-1 };

	SDL_SetRenderDrawColor((SDL_Renderer *)e.renderer(), 0, 0, 0, 255);
	SDL_RenderFillRect((SDL_Renderer *)e.renderer(), &rect);
	return true;
}

bool SpriteSDLFactory::creer(Element &e, Sprite **s)
{
	switch (e.type()) {
		case ElementType::BRIQUE:
		case ElementType::BRIQUE_INCASSABLE:
			*s = new SpriteBriqueSDL(e);
			break;
		case ElementType::BALLE:
			*s = new SpriteBalleSDL(e);
			break;
		case ElementType::CANEVAS:
			*s = new SpriteCanevasSDL(e);
			break;
		default:
			return false;
	}

	m_list.push_back(*s);
	return true;
}

bool SpriteSDLFactory::creer(SpriteObservateur &o, Element &e, SpriteObserve **s)
{
	switch (e.type()) {
		case ElementType::RAQUETTE:
			*s = new SpriteRaquetteSDL(o, e);
			break;
		default:
			return false;
	}

	m_list.push_back(*s);
	return true;
}
