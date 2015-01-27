#include <system/psycho2.cc>

#include <memory>

#include "gtest/gtest.h"

#include <engine/scene.h>

TEST(PsychoTest, NoReleaseCrash) {
  // Can't crash even if called alone
  EXPECT_EXIT(psy::system::Release(); exit(0), ::testing::ExitedWithCode(0), "");
}

TEST(PsychoTest, FocusCalled) {
  // Focus callback should be called when entering a Scene
  std::shared_ptr<psy::engine::Scene> s(new psy::engine::Scene);
  bool called_focus = false;
  s->set_focus_callback([&called_focus](psy::engine::Scene &self) {
    self.Finish();
    called_focus = true;
  });
  psy::system::Init();
  psy::system::ChangeTo(s);
  psy::system::Run();
  EXPECT_TRUE(called_focus);
}

TEST(PsychoTest, ChangingScenesOnFocus) {
  // Changing a Scene on its focus callback should cause no problems
  std::shared_ptr<psy::engine::Scene> a(new psy::engine::Scene), b(new psy::engine::Scene);
  bool called_focus_a, called_defocus_a, called_focus_b, called_defocus_b;
  called_focus_a = called_defocus_a = called_focus_b = called_defocus_b = false;
  a->set_focus_callback([&called_focus_a, &b](psy::engine::Scene&) {
    called_focus_a = true;
    psy::system::ChangeTo(b);
  });
  a->set_defocus_callback([&](psy::engine::Scene&) { called_defocus_a = true; });
  b->set_focus_callback([&called_focus_b](psy::engine::Scene &self) { 
    called_focus_b = true;
    self.Finish();
  });
  b->set_defocus_callback([&](psy::engine::Scene&) { called_defocus_b = true; });
  psy::system::Init();
  psy::system::ChangeTo(a);
  psy::system::Run();
  EXPECT_TRUE(called_focus_a);
  EXPECT_TRUE(called_defocus_a);
  EXPECT_TRUE(called_focus_b);
  EXPECT_TRUE(called_defocus_b);
}

TEST(PsychoTest, NoScene) {
  // Running the game without a Scene should not crash, just close immediately
  psy::system::Init();
  EXPECT_EXIT({
    psy::system::Run();
    psy::system::Release();
    exit(0);
  }, ::testing::ExitedWithCode(0), "");
}
