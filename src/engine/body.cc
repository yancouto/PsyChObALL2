#include <engine/body.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace psy {
namespace engine {

Body::Body(float x, float y) {
  transform_.setPosition(x, y);
}

Body::Body(const sf::Vector2f &position) : Body(position.x, position.y) {}

Body::~Body() {}

}  // namespace engine
}  // namespace psy
