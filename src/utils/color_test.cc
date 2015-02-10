#include <utils/color.cc>

#include "gtest/gtest.h"

TEST(ColorTest, AlphaReceived) {
  EXPECT_EQ(65, psy::utils::PsychoColor(sf::Time(), 65).a);
  EXPECT_EQ(43, psy::utils::PsychoColor(sf::milliseconds(690), 43).a);
  EXPECT_EQ(65, psy::utils::TrigoColor(sf::Time(), 65).a);
  EXPECT_EQ(43, psy::utils::TrigoColor(sf::milliseconds(690), 43).a);
}

TEST(ColorTest, AlphaDefault) {
  EXPECT_EQ(255, psy::utils::PsychoColor(sf::Time()).a);
  EXPECT_EQ(255, psy::utils::PsychoColor(sf::milliseconds(690)).a);
  EXPECT_EQ(255, psy::utils::TrigoColor(sf::Time()).a);
  EXPECT_EQ(255, psy::utils::TrigoColor(sf::milliseconds(690)).a);
}

TEST(ColorTest, PatternFunction) {
  psy::utils::ColorFunction psycho = 
    psy::utils::ColorFunction(static_cast<psy::utils::ColorFunctionRaw>(psy::utils::PsychoColor));
  psy::utils::ColorFunction trigo = 
    psy::utils::ColorFunction(static_cast<psy::utils::ColorFunctionRaw>(psy::utils::TrigoColor));
  psy::utils::ColorPattern pat(psycho);
  EXPECT_EQ(pat.color_func()(sf::seconds(1), 0), psycho(sf::seconds(1), 0));
  pat.set_color_func(trigo);
  EXPECT_EQ(pat.color_func()(sf::seconds(1.5), 0), trigo(sf::seconds(1.5), 0));
}

TEST(ColorTest, ColorChangerInitial) {
  psy::utils::ColorFunction func = psy::utils::ColorChanger(sf::Color::Red, 1.);
  EXPECT_EQ(func(sf::Time(), 255), sf::Color::Red);
  psy::utils::ColorFunction func2 = psy::utils::ColorChanger(sf::Color::Green, 1.);
  EXPECT_EQ(func2(sf::Time(), 255), sf::Color::Green);
}