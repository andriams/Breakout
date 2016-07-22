#include <Element/Element.h>

using namespace breakout;

Element::Element(const Vec2D<int> &p) : m_position(p) { };

void Element::setPosition(const Vec2D<int> &p)
{
	m_position = p;
}

Vec2D<int> Element::getPosition(void) const
{
	return m_position;
}

