#include <psycho2.h>

#include "gtest/gtest.h"

TEST(TestTests, NoCrash) {
  psy::system::Release();  // can't crash even if called alone
}
