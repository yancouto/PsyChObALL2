#include <entities/player.h>

#include <cmath>
#include <cstdio>
#include <map>
#include <functional>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <utils/math.h>

namespace psy {
namespace entities {

typedef sf::Keyboard::Key Key;

Player::Player(float x, float y) : 
  Body(x, y), 
  circle_shape_(100.f, 3),
  // Key pressed control map initialization.
  key_pressed_controls_ {
    // [WASD control callbacks.]
    {Key::W, [this](const sf::RenderWindow&, const sf::Time &dt) {
      circle_shape_.move(0, -1);
    }},
    {Key::A, [this](const sf::RenderWindow&, const sf::Time &dt) {
      circle_shape_.move(-1, 0);  
    }},
    {Key::S, [this](const sf::RenderWindow&, const sf::Time &dt) {
      circle_shape_.move(0, 1);
    }},
    {Key::D, [this](const sf::RenderWindow&, const sf::Time &dt) {
      circle_shape_.move(1, 0);
    }}
    // [/WASD control callbacks.]
  } {

  // Intiializes all the separate drawable entities.
  circle_shape_.setFillColor(sf::Color::Green);
  float r = circle_shape_.getRadius();
  circle_shape_.setOrigin(r, r);
  circle_shape_.setPosition(400, 300);
}

Player::Player(const sf::Vector2f &position) : 
  Player(position.x, position.y) {}

Player::~Player() {}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(circle_shape_, states);
}

void Player::Update(const sf::RenderWindow &window, const sf::Time &dt) {
  // Iterate through the KeyPressed control map and check if Key has been
  // pressed. If true, then call its control callback.
  for (auto it_keys_pressed = key_pressed_controls_.begin();
       it_keys_pressed != key_pressed_controls_.end();
       ++it_keys_pressed) {
    if (sf::Keyboard::isKeyPressed(it_keys_pressed->first))  // Gets Key.
      it_keys_pressed->second(window, dt);                   // Calls Value.
  }
  
  // Coordenates mouse movement and shape rotation.
  sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
  sf::Vector2f player_position = circle_shape_.getPosition();
  mouse_position_ = mouse_position;
  // Finds the angle to be rotated in radians.
  float angle = atan2(mouse_position.y - player_position.y,
                      mouse_position.x - player_position.x);
  angle = psy::utils::math::rad_to_deg(angle);  // Converts to degrees.
  //circle_shape_.setRotation(angle);
  circle_shape_.setRotation(angle);

  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    printf("Mouse position = [%d, %d]\n", mouse_position.x, mouse_position.y);  
}

}  // namespace entities
}  // namespace psy
