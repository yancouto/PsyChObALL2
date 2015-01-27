// Test module for MainMenu.
// @see MainMenu

#include <menu/main_menu.cc>

#include "gtest/gtest.h"

TEST(MainMenuTest, SceneNonNull) {
  EXPECT_NE(psy::menu::MainMenuScene(), nullptr);
}

// TODO: Better Tests
