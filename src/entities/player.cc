#include <entities/player.h>

#include <cmath>
#include <cstdio>

#include <SFML/System.hpp>

#include <system/globals.h>
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
    {Key::W, [this](const sf::Time &dt) {
      circle_shape_.move(0, -5);
    }},
    {Key::A, [this](const sf::Time &dt) {
      circle_shape_.move(-5, 0);  
    }},
    {Key::S, [this](const sf::Time &dt) {
      circle_shape_.move(0, 5);
    }},
    {Key::D, [this](const sf::Time &dt) {
      circle_shape_.move(5, 0);
    }},
    {Key::Q, [this](const sf::Time &dt) {
      // Repeats itself a lot, but screw it, it's just a test
      pattern_.set_color_func(psy::utils::kPsychoColorFunction);
    }},
    {Key::E, [this](const sf::Time &dt) {
      // Just a test
      pattern_.set_color_func(psy::utils::kTrigoColorFunction);
    }}
    // [/WASD control callbacks.]
  },
  pattern_(psy::utils::ColorChanger(sf::Color::Magenta, 100.)) {

  // Initializes all the separate drawable entities.
  circle_shape_.setFillColor(pattern_.CurrentColor());
  float r = circle_shape_.getRadius();
  circle_shape_.setOrigin(r, r);
  circle_shape_.setPosition(x, y);
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
  
  // Coordenates mouse movement and shape rotation.
  sf::Vector2f player_position = circle_shape_.getPosition();
  // Finds the angle to be rotated in radians.
  float angle = atan2(psy::system::mouse_position.y - player_position.y,
                      psy::system::mouse_position.x - player_position.x);
  angle = psy::utils::math::RadToDeg(angle);  // Converts to degrees.
  //circle_shape_.setRotation(angle);
  circle_shape_.setRotation(angle);

  circle_shape_.setFillColor(pattern_.CurrentColor());
}

}  // namespace entities
}  // namespace psy
