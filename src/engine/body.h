#ifndef PSYCHO_ENGINE_BODY_H_
#define PSYCHO_ENGINE_BODY_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace psy {
namespace engine {

class Body : public sf::Drawable {
 public:
  Body(float x, float y);
  explicit Body(const sf::Vector2f &position);
  virtual ~Body();

  virtual void draw(
    sf::RenderTarget &target, 
    sf::RenderStates states) const = 0;

  sf::Transformable& transform() { return transform_; }
  const sf::Transformable& const_transform() const { return transform_; }
 private:
  // Used for transformation of this Body.
  sf::Transformable transform_;
};

}  // namespace engine
}  // namespace psy

#endif // PSYCHO_ENGINE_BODY_H_
