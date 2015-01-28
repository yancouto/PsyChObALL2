#include <entities/player.cc>

#include "gtest/gtest.h"

#include <map>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Tests whether the default control keys are set on construction.
TEST(PlayerTest, KeyPressedMap) {
  psy::entities::Player target_player(0, 0);
  auto controls = target_player.key_pressed_controls();
  // Avoiding too much time-consuming typing.
  typedef sf::Keyboard::Key Key;
  Key default_controls[] = {Key::W, Key::A, Key::S, Key::D};
  int size = sizeof(default_controls)/sizeof(default_controls[0]);
  
  for (int i = 0; i < size; ++i)
    EXPECT_NE(controls.find(default_controls[i]), controls.end());
}
