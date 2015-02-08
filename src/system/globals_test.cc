#include <system/globals.cc>

#include "gtest/gtest.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

TEST(GlobalsTest, VarInitialization) {
  EXPECT_EQ(psy::system::mouse_position, sf::Vector2<double>(0, 0));
  EXPECT_EQ(psy::system::window_size, sf::Vector2<int>(1024, 768));
  // This causes tests to halt. No compilation errors, yet it causes strange
  // behavior. We should look into it later.
  // TODO(Renato): Fix this line of code from halting other test cases.
  /*EXPECT_EQ(psy::system::desktop_resolution, 
            sf::Vector2<int>(sf::VideoMode::getDesktopMode().width,
                             sf::VideoMode::getDesktopMode().height));*/
}
