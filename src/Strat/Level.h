#pragma once

#include <list>

#include <Element/Brick.h>

namespace breakout {

	class Level {
			using element_t = std::list<Element*>;
		public:
			using iterator = element_t::iterator;

			Level(int element_restants) : m_element_restants(element_restants) {}

			bool add(Element &b) {
				m_element.push_back(&b);
				return true;
			}

			bool del(Element &b) {
				m_element.remove(&b);
				m_element_restants --;
				return true;
			}

			bool isEnding() { return m_element_restants == 0; }

			/* iterateur sur les element */
			iterator begin() { return m_element.begin(); }
			iterator end() { return m_element.end(); }

		private:
			unsigned m_element_restants;
			element_t m_element;

	};

}
