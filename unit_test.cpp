#include "googletest/googletest/include/gtest/gtest.h"

#include "dispTest.hpp"
#include "DisplayStrategy.hpp"
#include "baseTest.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
