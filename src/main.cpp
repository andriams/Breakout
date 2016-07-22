#include <stdlib.h>
#include <string>

#include <Strat/Level1.h>
#include <Element/Brick.h>
#include <Element/Canvas.h>
#include <Screen/ScreenSDL.h>

#include <Physic/Physic2DLowRes.h>

#include <Game.h>

using namespace breakout;

int main(int argc, char **argv)
{
	ScreenSDL screen;
	Level1 level1;
	Physique2DLowRes physic;

	Game game(screen, physic);
	game.start(level1);

	Action action;
	
	do { 
		action = screen.getAction();
		game.show();
	} while(game.execute(action));

	return EXIT_SUCCESS;
}
