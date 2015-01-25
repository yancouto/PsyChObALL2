//
// Test case for Scene.
//
// @see Scene
// @see Task
//

#include "gtest/gtest.h"

#include <engine/scene.h>

// TODO(Renato): Work on more elaborate tests (which require private members).

// Tests the reliability of focusing and defocusing a Scene.
TEST(SceneTest, FocusValidity) {
  psy::Scene target_scene;
  EXPECT_FALSE(target_scene.active());
  target_scene.Focus();
  EXPECT_TRUE(target_scene.active());
  target_scene.DeFocus();
  EXPECT_FALSE(target_scene.active());
}

// Tests the reliability of finishing a Scene.
TEST(SceneTest, FinishValidity) {
  psy::Scene target_scene;
  EXPECT_FALSE(target_scene.finished());
  target_scene.Finish();
  EXPECT_TRUE(target_scene.finished());
}

