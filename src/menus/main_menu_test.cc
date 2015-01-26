// Test module for MainMenu.
// @see MainMenu

#include "gtest/gtest.h"

#include <menus/main_menu.cc>

TEST(MainMenuTest, FpsCounterInit) {
  psy::MainMenu target_menu;
  EXPECT_EQ(target_menu.fps_counter(), 1);
}
