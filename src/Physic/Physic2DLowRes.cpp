
#include <Physic/Physic2DLowRes.h>

using namespace breakout;

bool Physique2DLowRes::canvas(Sprite *canvas, int min_x, int min_y, int max_x, int max_y)
{
	m_canvas = canvas;
	m_sprites.clear();

	m_x_max = max_x;
	m_y_max = max_y;

	//m_sprites = new Sprite* [max_x][max_y];
	m_sprites.resize(max_y);
	for (int y = 0; y < max_y; y++) {
		m_sprites[y].resize(max_x);
	}

	/* clear */
	mark(Vec2D<int>(0, 0), Vec2D<int>(max_x, max_y), nullptr);

	/* canvas */
	mark(Vec2D<int>(0, 0), Vec2D<int>(min_x, max_y), canvas);
	mark(Vec2D<int>(0, 0), Vec2D<int>(max_x, min_y), canvas);
	return true;
}

bool Physique2DLowRes::add(Sprite &s)
{
	m_obs_position[&s] = Vec2DDoubleToInt(s.getPosition());
	Vec2D<int> v = m_obs_position[&s];
	return mark(Vec2DDoubleToInt(s.getPosition()), s.getSize(), &s);
}

bool Physique2DLowRes::del(Sprite &s)
{
	Vec2D<int> old_position = m_obs_position[&s];
	return mark(old_position, s.getSize(), nullptr);
}

bool Physique2DLowRes::mark(const Vec2D<int> &pos, const Vec2D<int> &dim, Sprite *obj)
{
	int pos_x, pos_y;
	int max_pos_x, max_pos_y;
	int dim_x, dim_y;

	pos.getCoord(pos_x, pos_y);
	dim.getCoord(dim_x, dim_y);

	max_pos_x = pos_x + dim_x;
	max_pos_y = pos_y + dim_y;

	if (max_pos_x > m_x_max || max_pos_y > m_y_max) {
		return false;
	}

	for (int x = pos_x; x < max_pos_x; x++) {
		for (int y = pos_y; y < max_pos_y; y++) {
			m_sprites[y][x] = obj;
		}
	}
	return true;
}

bool Physique2DLowRes::collision(const Sprite &objet, const Vec2D<int> &v, Sprite **meet) const
{
	int pos_x, pos_y;
	int max_pos_x, max_pos_y;
	int dim_x, dim_y;

	Vec2D<int> dim = objet.getSize();

	v.getCoord(pos_x, pos_y);
	dim.getCoord(dim_x, dim_y);

	max_pos_x = pos_x + dim_x;
	max_pos_y = pos_y + dim_y;

	if (max_pos_x > m_x_max) {
		*meet = m_canvas;
		return true;
	}

	if (max_pos_y > m_y_max) {
		*meet = m_canvas;
		return true;
	}

	for (int y = pos_y; y < max_pos_y; y++) {
		for (int x = pos_x; x < max_pos_x; x++) {
			*meet = m_sprites[y][x];
			if (*meet != nullptr) {
				if (*meet == &objet) {
					continue;
				}
				
				return true;
			}
		}
	}

	return false;
}

/* debug function */
void Physique2DLowRes::dump(std::ostream &out) const
{
	out << std::endl;
	for (int y = 0; y < m_y_max; y++) {
		for (int x = 0; x < m_x_max; x++) {
			if (m_sprites[y][x]) {
				out << "#";
			} else {
				out << ".";
			}
		}
		out << std::endl;
	}
	out << std::endl;
}

