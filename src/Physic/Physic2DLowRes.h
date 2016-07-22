#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <Screen/Sprite.h>
#include <Screen/SpriteObservable.h>
#include <Physic/Physic2D.h>

namespace breakout {

	class Physique2DLowRes : public Physic2D {
		public:
			Physique2DLowRes() {}
			~Physique2DLowRes() override { remove(); }

			bool canvas(Sprite *canevas, int min_x, int min_y, int max_x, int max_y) override;

			bool collision(const Sprite &sprite, const Vec2D<int> &v, Sprite **rencontre) const override;

			bool add(Sprite &s) override;
			bool del(Sprite &s) override;

			void dump(std::ostream &out) const override;

		private:
			void remove() { m_sprites.clear(); }
			bool mark(const Vec2D<int> &pos, const Vec2D<int> &dim, Sprite *obj);

			/* dimension autorisées et objet associé */
			int m_x_max;
			int m_y_max;
			Sprite *m_canvas;

			/* tableau des objets par Vecteur */
			std::vector<std::vector<Sprite*>> m_sprites;

			std::unordered_map<const Sprite*, Vec2D<int>> m_obs_position;
	};

}
