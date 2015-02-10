#ifndef PSY_ENTITIES_PLAYER_H_
#define PSY_ENTITIES_PLAYER_H_

#include <map>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <engine/body.h>
#include <utils/color.h>

namespace psy {
namespace entities {

class Player : public engine::Body {
 public:
  using KeyboardMap = std::map<sf::Keyboard::Key, std::function<void (const sf::Time&)>>;

  Player(float x, float y);
  explicit Player(const sf::Vector2f &position);
  virtual ~Player();

  virtual void draw(sf::RenderTarget &target, 
                    sf::RenderStates states) const override;
  virtual void Update(const sf::Time &dt);

  KeyboardMap& key_pressed_controls() { return key_pressed_controls_; }

 private:
  sf::CircleShape circle_shape_;
  KeyboardMap key_pressed_controls_;
  // Color calculation
  psy::utils::ColorPattern pattern_;
};

}  // namespace entities
}  // namespace psy

#endif  // PSY_ENTITIES_PLAYER_H_
