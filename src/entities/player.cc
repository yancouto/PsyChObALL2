#include <entities/player.h>

#include <map>
#include <functional>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace psy {
namespace entities {

typedef sf::Keyboard::Key Key;

Player::Player(float x, float y) : 
  Body(x, y), 
  circle_shape_(100.f),
  // Key pressed control map initialization.
  key_pressed_controls_ {
    // [WASD control callbacks.]
    {Key::W, [this](const sf::Time &dt) {
      circle_shape_.move(0, -1);
    }},
    {Key::A, [this](const sf::Time &dt) {
      circle_shape_.move(-1, 0);  
    }},
    {Key::S, [this](const sf::Time &dt) {
      circle_shape_.move(0, 1);
    }},
    {Key::D, [this](const sf::Time &dt) {
      circle_shape_.move(1, 0);
    }}
    // [/WASD control callbacks.]
  } {
  circle_shape_.setFillColor(sf::Color::Green);
  circle_shape_.setPosition(400, 300);
}

Player::Player(const sf::Vector2f &position) : 
  Player(position.x, position.y) {}

Player::~Player() {}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(circle_shape_, states);
}

void Player::Update(const sf::Time &dt) {
  // Iterate through the KeyPressed control map and check if Key has been
  // pressed. If true, then call its control callback.
  for (auto it_keys_pressed = key_pressed_controls_.begin();
       it_keys_pressed != key_pressed_controls_.end();
       ++it_keys_pressed) {
    if (sf::Keyboard::isKeyPressed(it_keys_pressed->first))  // Gets Key.
      it_keys_pressed->second(dt);                           // Calls Value.
  } 
}

}  // namespace entities
}  // namespace psy
