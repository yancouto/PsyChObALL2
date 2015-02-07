#include <system/globals.cc>

#include "gtest/gtest.h"

#include <SFML/System.hpp>

TEST(GlobalsTest, VarInitialization) {
  EXPECT_EQ(psy::system::mouse_position, sf::Vector2<double>(0, 0));
  EXPECT_EQ(psy::system::window_size, sf::Vector2<int>(800, 600)); 
}
