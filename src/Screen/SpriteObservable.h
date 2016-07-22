#pragma once

#include <Screen/Screen.h>
#include <Screen/Sprite.h>

namespace breakout {

	class Screen;
	class Sprite;
	class SpriteObservable;

	class SpriteObserver {
		public:
			virtual bool update(SpriteObservable &) = 0;
	};

	class SpriteObservable {
		public:
			SpriteObservable(SpriteObserver &o, Sprite &s) : m_sprite(s), m_observer(o) {}
			Sprite &sprite() { return m_sprite; }

		protected:
			void update() { m_observer.update(*this); }

		private:
			Sprite &m_sprite;
			SpriteObserver &m_observer;
	};

}
