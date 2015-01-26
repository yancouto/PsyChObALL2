// Test module for MainMenu.
// @see MainMenu

#include "gtest/gtest.h"

#include <menus/main_menu.cc>

TEST(MainMenuTest, SceneNonNull) {
  EXPECT_NE(psy::MainMenuScene(), nullptr);
}

// TODO: Better Tests