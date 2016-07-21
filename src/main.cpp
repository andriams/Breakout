#include <stdlib.h>
#include <string>

#include <Strat/Niveau1.h>
#include <Element/Brique.h>
#include <Element/Canevas.h>
#include <Ecran/EcranSDL.h>

#include <Physique/Physique2DFaibleRes.h>

#include <Jeu.h>

using namespace cassebrique;

int main(int argc, char **argv)
{
	EcranSDL ecran;
	Niveau1 niveau1;
	Physique2DFaibleRes physique;

	Jeu jeu(ecran, physique);
	jeu.demarrer(niveau1);

	Action action;
	
	do { 
		action = ecran.lireAction();
		jeu.afficher();
	} while(jeu.executer(action));

	return EXIT_SUCCESS;
}
