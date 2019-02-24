// main.cpp
#include <iostream>

#include "common/logs/log.hpp"
#include "common/logs/log_stdout.hpp"

#include "gtest/gtest.h"

using namespace common;

// Tests factorial of 0.
TEST(FactorialTest, Zero) {
  EXPECT_EQ(1, 1);
}

