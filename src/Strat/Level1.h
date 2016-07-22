#pragma once

#include <array>

#include <Strat/Level.h>

namespace breakout {

	class Level1 : public Level {
		public:

			Level1() : Level(bn.size()) {
				bn = { {
					Brick(Vec2D<int>(7, 2), Color::WHITE),
					Brick(Vec2D<int>(6, 2), Color::WHITE),
					Brick(Vec2D<int>(9, 2), Color::WHITE),
					Brick(Vec2D<int>(11, 2), Color::WHITE),
					Brick(Vec2D<int>(7, 1), Color::WHITE),
					Brick(Vec2D<int>(6, 1), Color::WHITE),
					Brick(Vec2D<int>(9, 1), Color::WHITE),
					Brick(Vec2D<int>(11, 1), Color::WHITE)
					} };
				bi = { {
				   BrickUnbrokable(Vec2D<int>(8, 1)),
				   BrickUnbrokable(Vec2D<int>(12, 1)),
				   BrickUnbrokable(Vec2D<int>(2, 1)),
				   BrickUnbrokable(Vec2D<int>(3, 1)),
				   BrickUnbrokable(Vec2D<int>(4, 1)),
				   BrickUnbrokable(Vec2D<int>(5, 1))
				   } };

				for ( Brick &b : bn ) {
					add(b);
				}
				for (BrickUnbrokable &b : bi) {
					add(b);
				}
			};

		private:
			std::array<Brick, 8>           bn; 
			std::array<BrickUnbrokable, 6> bi;
	};

}
