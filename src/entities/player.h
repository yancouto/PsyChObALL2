#ifndef PSYCHO_ENTITIES_PLAYER_H_
#define PSYCHO_ENTITIES_PLAYER_H_

#include <engine/body.h>

#include <SFML/Graphics.hpp>

namespace psy {
namespace entities {

class Player : public engine::Body {
 public:
  Player(float x, float y);
  explicit Player(const sf::Vector2f &position);
  virtual ~Player();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states);

 private:
  sf::CircleShape circle_shape_;
};

}  // namespace entities
}  // namespace psy

#endif  // PSYCHO_ENTITIES_PLAYER_H_
