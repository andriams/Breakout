#pragma once

#include <math.h>

#include <Geom/Vec2D.h>
#include <Element/Brick.h>
#include <Element/Racket.h>
#include <Element/Ball.h>
#include <Element/Canvas.h>
#include <Screen/Screen.h>
#include <Screen/SpriteObservable.h>

namespace breakout {

	class Sprite {
		public:
			Sprite(const Vec2D<double> &p, const Vec2D<int> &t, Element &e) : 
				m_position(p), m_movement(Vec2D<double>(0,0)), m_size(t), m_element(e) {}
			virtual ~Sprite() {}

			/* size of sprite */
			void setSize(const Vec2D<int> &size) { m_size = size; }
			Vec2D<int> getSize() const { return m_size; }

			/* movement of sprite */
			void setMovement(const Vec2D<double> &movement) { m_movement = movement; }
			Vec2D<double> getMovement() const { return m_movement; }

			/* position */
			Vec2D<double> getPosition() const { return m_position; }
			virtual void setPosition(const Vec2D<double> &position) { m_position = position; }
			virtual void move(const Vec2D<double> &mouvement) { m_position += mouvement; }

			/* show on screern*/
			virtual bool show(Screen &) = 0;

			/* get element */
			Element &element() { return m_element; }
		protected:
			Vec2D<double> m_position;
			Vec2D<double> m_movement;
			Vec2D<int> m_size;
			Element &m_element;
	};

	/* observed sprite used for tracked sprites */
	class SpriteObserved : public Sprite, public SpriteObservable {
		public:
			SpriteObserved(SpriteObserver &o,
				const Vec2D<double> &p,
				const Vec2D<int> &t,
				Element &r) : Sprite(p, t, r), SpriteObservable(o, *this) {}

			/* observable */
			void setPosition(const Vec2D<double> &position) override {
				m_position = position;
				update();
			}

			void move(const Vec2D<double> &mouvement) override {
				m_position += mouvement;
				update();
			}
	};

	/* the racket is observed */
	class SpriteRacket : public SpriteObserved {
		public:
			SpriteRacket(SpriteObserver &o,
				const Vec2D<double> &p,
				const Vec2D<int> &t,
				Element &r) : SpriteObserved(o, p, t, r) {}

	};

}
