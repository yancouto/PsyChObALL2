// Test module for MainMenu.
// @see MainMenu

#include "gtest/gtest.h"

#include <menus/main_menu.cc>

TEST(MainMenuTest, SceneNonNull) {
  EXPECT_NE(psy::menu::MainMenuScene(), nullptr);
}

TEST(MainMenuTest, FpsCounterInit) {
  EXPECT_EQ(fps_counter, 1);
}

// TODO: Better Tests
