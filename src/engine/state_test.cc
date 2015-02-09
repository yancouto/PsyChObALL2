//
// Test case for State.
//
// @see State
// @see Task
//

#include "gtest/gtest.h"

#include <engine/state.cc>

// TODO(Renato): Work on more elaborate tests (which require private members).

// Tests the reliability of focusing and defocusing a State.
TEST(StateTest, FocusValidity) {
  psy::engine::State target_state;
  EXPECT_FALSE(target_state.active());
  target_state.Focus();
  EXPECT_TRUE(target_state.active());
  target_state.DeFocus();
  EXPECT_FALSE(target_state.active());
}

// Tests the reliability of finishing a State.
TEST(StateTest, FinishValidity) {
  psy::engine::State target_state;
  EXPECT_FALSE(target_state.finished());
  target_state.Finish();
  EXPECT_TRUE(target_state.finished());
}

