#include <psycho2.h>

#include "gtest/gtest.h"

TEST(TestTests, Test1) {  // test
  EXPECT_TRUE(true);      // test
}                         // test

TEST(TestTests, NoCrash) {
  psy::system::Release();  // can't crash even if called alone
}
