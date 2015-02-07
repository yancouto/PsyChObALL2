#include <utils/math.cc>

#include "gtest/gtest.h"

#include <cmath>

TEST(MathTest, PiDefinition) {
  EXPECT_EQ(psy::utils::math::kPi, M_PI);
}

TEST(MathTest, RadToDeg) {
  EXPECT_EQ(psy::utils::math::rad_to_deg(0), 0);
  EXPECT_EQ(psy::utils::math::rad_to_deg(M_PI/4), 45);
  EXPECT_EQ(psy::utils::math::rad_to_deg(M_PI/2), 90);
  EXPECT_EQ(psy::utils::math::rad_to_deg(M_PI), 180);
  EXPECT_EQ(psy::utils::math::rad_to_deg(2*M_PI), 360);
}

TEST(MathTest, DegToRad) {
  EXPECT_EQ(psy::utils::math::deg_to_rad(0), 0);
  EXPECT_EQ(psy::utils::math::deg_to_rad(45), M_PI/4);
  EXPECT_EQ(psy::utils::math::deg_to_rad(90), M_PI/2);
  EXPECT_EQ(psy::utils::math::deg_to_rad(180), M_PI);
  EXPECT_EQ(psy::utils::math::deg_to_rad(360), 2*M_PI);
}
