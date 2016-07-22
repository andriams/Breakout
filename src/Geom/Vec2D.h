#pragma once

#include <math.h>

namespace breakout
{
	/* template */

	template <class T>
	class Vec2D {
		public:
			Vec2D() : m_x(0), m_y(0) {}
			Vec2D(T x, T y);

			void setCoord(T x, T y);

			void getCoord(T &x, T &y) const;

			Vec2D<T>& operator+=(const Vec2D<T> &rhs);
			Vec2D<T>& operator-=(const Vec2D<T> &rhs);
			Vec2D<T>   operator+(const Vec2D<T> &rhs) const;
			Vec2D<T>   operator-(const Vec2D<T> &rhs) const;

			bool operator==(const Vec2D<T> &rhs) const;
			bool operator!=(const Vec2D<T> &rhs) const;

		private:
			T m_x;
			T m_y;
	};

	/* helper */
	static inline Vec2D<int> Vec2DDoubleToInt(const Vec2D<double> &d) {
		double x,y; d.getCoord(x, y);
		return Vec2D<int>(floor(x + 0.5), floor(y + 0.5)); }

#include <Geom/Vec2D.tpp>

}
