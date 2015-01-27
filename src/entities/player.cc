#include <entities/player.h>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace psy {
namespace entities {
 
Player::Player(float x, float y) : B(x, y), circle_shape_(100.f) {
  circle_shape.setFillColor(sf::Color::Green);
  circle_shape.setPosition(400, 300);
}
Player::Player(const sf::Vector2f &position) : 
  Player(position.x, position.y) {}

Player::~Player() {}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) {
  target.draw(circle_shape_, states);
}

}  // namespace entities
}  // namespace psy
