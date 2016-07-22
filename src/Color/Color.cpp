#include <Color/Color.h>

using namespace breakout;

namespace breakout {
	std::string ColorToString(Color c) {
		switch(c) {
			case Color::BLUE: return "BLUE";
			case Color::WHITE: return "WHITE";
			case Color::RED: return "RED";
		}
		return "ERROR";
	}
}

