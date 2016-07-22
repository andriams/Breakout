#include <Interface/Obstacle.h>

namespace breakout {
	std::string ObstacleResultToString(ObstacleResult r) {
		switch(r) {
			case ObstacleResult::UNBROKEN: return "UNBROKEN";
			case ObstacleResult::BROKEN: return "BROKEN";
		}
		return "ERROR";
	}
}
