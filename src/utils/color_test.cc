#include <utils/color.cc>

#include "gtest/gtest.h"

TEST(ColorTest, AlphaReceived) {
  EXPECT_EQ(65, psy::utils::PsychoColor(sf::Time(), 65).a);
  EXPECT_EQ(43, psy::utils::PsychoColor(sf::milliseconds(690), 43).a);
}

TEST(ColorTest, AlphaDefault) {
  EXPECT_EQ(255, psy::utils::PsychoColor(sf::Time()).a);
  EXPECT_EQ(255, psy::utils::PsychoColor(sf::milliseconds(690)).a);
}