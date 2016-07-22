
#include <Physic/Physic2D.h>

using namespace breakout;

bool Physic2D::update(SpriteObservable &obs)
{
	Sprite &s = obs.sprite();
	del(s);
	return add(s);
}

