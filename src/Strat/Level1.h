#pragma once

#include <array>

#include <Strat/Niveau.h>

namespace cassebrique {

	class Niveau1 : public Niveau {
		public:

			Niveau1() : Niveau(bn.size()) {
				bn = { {
					Brique(Vecteur<int>(7, 2), Couleur::BLANC),
					Brique(Vecteur<int>(6, 2), Couleur::BLANC),
					Brique(Vecteur<int>(9, 2), Couleur::BLANC),
					Brique(Vecteur<int>(11, 2), Couleur::BLANC),
					Brique(Vecteur<int>(7, 1), Couleur::BLANC),
					Brique(Vecteur<int>(6, 1), Couleur::BLANC),
					Brique(Vecteur<int>(9, 1), Couleur::BLANC),
					Brique(Vecteur<int>(11, 1), Couleur::BLANC)
					} };
				bi = { {
				   BriqueIncassable(Vecteur<int>(8, 1)),
				   BriqueIncassable(Vecteur<int>(12, 1)),
				   BriqueIncassable(Vecteur<int>(2, 1)),
				   BriqueIncassable(Vecteur<int>(3, 1)),
				   BriqueIncassable(Vecteur<int>(4, 1)),
				   BriqueIncassable(Vecteur<int>(5, 1))
				   } };

				for ( Brique &b : bn ) {
					ajouter(b);
				}
				for ( BriqueIncassable &b : bi ) {
					ajouter(b);
				}
			};

		private:
			std::array<Brique, 8>           bn; /*{ {
				Brique(Vecteur<int>(7, 2), Couleur::BLANC),
				Brique(Vecteur<int>(8, 2), Couleur::BLANC),
				Brique(Vecteur<int>(9, 2), Couleur::BLANC),
				Brique(Vecteur<int>(10, 2), Couleur::BLANC),
			} };*/
			std::array<BriqueIncassable, 6> bi;/* { {
				BriqueIncassable(Vecteur<int>(0, 1)),
				BriqueIncassable(Vecteur<int>(1, 1)),
				BriqueIncassable(Vecteur<int>(2, 1)),
				BriqueIncassable(Vecteur<int>(3, 1)),
				BriqueIncassable(Vecteur<int>(4, 1)),
				BriqueIncassable(Vecteur<int>(5, 1))
			} };*/

	};

}
