#include <system/manager.cc>

#include <memory>

#include "gtest/gtest.h"

#include <engine/state.h>

TEST(ManagerTest, NoReleaseCrash) {
  // Can't crash even if called alone
  EXPECT_EXIT(psy::system::Release(); exit(0), ::testing::ExitedWithCode(0), "");
}

TEST(ManagerTest, FocusCalled) {
  // Focus callback should be called when entering a State
  std::shared_ptr<psy::engine::State> s(new psy::engine::State);
  bool called_focus = false;
  s->set_focus_callback([&called_focus](psy::engine::State &self) {
    self.Finish();
    called_focus = true;
  });
  psy::system::Init();
  psy::system::ChangeTo(s);
  psy::system::Run();
  EXPECT_TRUE(called_focus);
}

TEST(ManagerTest, ChangingStatesOnFocus) {
  // Changing a State on its focus callback should cause no problems
  std::shared_ptr<psy::engine::State> a(new psy::engine::State), b(new psy::engine::State);
  bool called_focus_a, called_defocus_a, called_focus_b, called_defocus_b;
  called_focus_a = called_defocus_a = called_focus_b = called_defocus_b = false;
  a->set_focus_callback([&called_focus_a, &b](psy::engine::State&) {
    called_focus_a = true;
    psy::system::ChangeTo(b);
  });
  a->set_defocus_callback([&](psy::engine::State&) { called_defocus_a = true; });
  b->set_focus_callback([&called_focus_b](psy::engine::State &self) { 
    called_focus_b = true;
    self.Finish();
  });
  b->set_defocus_callback([&](psy::engine::State&) { called_defocus_b = true; });
  psy::system::Init();
  psy::system::ChangeTo(a);
  psy::system::Run();
  EXPECT_TRUE(called_focus_a);
  EXPECT_TRUE(called_defocus_a);
  EXPECT_TRUE(called_focus_b);
  EXPECT_TRUE(called_defocus_b);
}

TEST(ManagerTest, NoState) {
  // Running the game without a State should not crash, just close immediately
  psy::system::Init();
  EXPECT_EXIT({
    psy::system::Run();
    psy::system::Release();
    exit(0);
  }, ::testing::ExitedWithCode(0), "");
}
