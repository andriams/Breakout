#pragma once

#include <array>

namespace breakout
{
	enum class ObstacleResult { UNBROKEN, BROKEN };
	std::string ObstacleResultToString(ObstacleResult r);

	class Obstacle {
		public:
			virtual ObstacleResult collision() const = 0;
	};
};
