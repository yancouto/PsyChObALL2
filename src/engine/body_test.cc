#include <engine/body.cc>

#include "gtest/gtest.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

TEST(BodyTest, BodyConstructor) {
  // Creates an implementation of abstract class Body.
  class : public psy::engine::Body {
   public:
    using psy::engine::Body::Body;
    void draw(sf::RenderTarget &canvas, 
              sf::RenderStates states) const override {}
  } float_init(5, 10), 
    vector_init(sf::Vector2f(5, 10));

  EXPECT_EQ(float_init.transform().getPosition(), 
            vector_init.transform().getPosition());
}
