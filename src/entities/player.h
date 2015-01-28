#ifndef PSYCHO_ENTITIES_PLAYER_H_
#define PSYCHO_ENTITIES_PLAYER_H_

#include <map>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <engine/body.h>

namespace psy {
namespace entities {

class Player : public engine::Body {
 public:
  typedef std::map<sf::Keyboard::Key, 
                   std::function<void (const sf::Time &dt)>> KeyboardMap;

  Player(float x, float y);
  explicit Player(const sf::Vector2f &position);
  virtual ~Player();

  virtual void draw(sf::RenderTarget &target, 
                    sf::RenderStates states) const override;
  virtual void Update(const sf::Time &dt);

  KeyboardMap& key_pressed_controls() { return key_pressed_controls_; }

 private:
  sf::CircleShape circle_shape_;
  std::map<
    sf::Keyboard::Key,                          // Keyboard key.
    std::function<void (const sf::Time &dt)>>   // Key pressed callback.
    key_pressed_controls_;
};

}  // namespace entities
}  // namespace psy

#endif  // PSYCHO_ENTITIES_PLAYER_H_
