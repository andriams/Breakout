#include <Geom/Vec2D.h>

using namespace breakout;

template <class T>
Vec2D<T>::Vec2D(T x, T y) : m_x(x), m_y(y) {}

template <class T>
void Vec2D<T>::setCoord(T x, T y)
{
	*this = Vec2D(x,y);
}

template <class T>
void Vec2D<T>::getCoord(T &x, T &y) const
{
	x = m_x;
	y = m_y;
}

template <class T>
Vec2D<T> Vec2D<T>::operator+(const Vec2D<T> &rhs) const
{
	return Vec2D<T>(m_x + rhs.m_x,
	                  m_y + rhs.m_y);
}

template <class T>
Vec2D<T> Vec2D<T>::operator-(const Vec2D<T> &rhs) const
{
	return Vec2D<T>(m_x - rhs.m_x,
                      m_y - rhs.m_y);
}

template <class T>
Vec2D<T>& Vec2D<T>::operator+=(const Vec2D<T> &rhs)
{
	*this = *this + rhs;

	return *this;
}

template <class T>
Vec2D<T>& Vec2D<T>::operator-=(const Vec2D<T> &rhs)
{
	*this = *this - rhs;
	return *this;
}

template <class T>
bool Vec2D<T>::operator==(const Vec2D<T> &rhs) const
{
	return (m_x == rhs.m_x) && (m_y == rhs.m_y);
}

template <class T>
bool Vec2D<T>::operator!=(const Vec2D<T> &rhs) const
{
	return !(*this == rhs);
}



