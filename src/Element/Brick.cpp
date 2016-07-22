#include <Element/Brick.h>

using namespace breakout;

Brick::Brick(const Vec2D<int> &v, Color color) : Element(v), m_color(color) {}
ObstacleResult Brick::collision() const { return ObstacleResult::BROKEN; }

BrickUnbrokable::BrickUnbrokable(const Vec2D<int> &v) : Brick(v, Color::RED) {}
ObstacleResult BrickUnbrokable::collision() const { return ObstacleResult::UNBROKEN; }

