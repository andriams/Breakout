#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <Screen/Sprite.h>
#include <Screen/SpriteObservable.h>

namespace breakout {

	class Physic2D : public SpriteObserver {
		public:
			Physic2D() {}
			virtual ~Physic2D() {}

			virtual bool canvas(Sprite *canevas, int min_x, int min_y, int max_x, int max_y) = 0;

			virtual bool collision(const Sprite &sprite, const Vec2D<int> &v, Sprite **rencontre) const = 0;

			virtual bool add(Sprite &s) = 0;
			virtual bool del(Sprite &s) = 0;

			virtual void dump(std::ostream &out) const = 0;

			/* observable */
			bool update(SpriteObservable &) override;


		protected:
			int m_x_min;
			int m_y_min;
			int m_x_max;
			int m_y_max;
			Sprite *m_canvas;
	};

}
