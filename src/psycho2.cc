#include "psycho2.h"

#include <SFML/Graphics.hpp>

namespace {
/* Main game window */
sf::RenderWindow *window = nullptr;
}  // namespace

namespace psy {
namespace system {

void Init() {
  window = new sf::RenderWindow(sf::VideoMode(200, 200), "PsyChObALL 2");
}

void Run() {
  sf::CircleShape shape(100.f);           // test
  shape.setFillColor(sf::Color::Green);  // test

  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) { // event handling
      if (event.type == sf::Event::Closed)
        window->close();
    }
    window->clear();
    window->draw(shape);  // test
    window->display();
  }
}

void Release() {
  if(window) delete window;
}

}  // namespace system
}  // namespace psy