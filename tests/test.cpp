// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <iostream>

#include "../../LAB32/include/proc_check.hpp"
TEST(Example, EmptyTest) {
  proc_check a;
  a.countDirect();
  std::cout << a;
  proc_check b;
  b.countReverse();
  std::cout << b;
  proc_check c;
  c.countRandom();
  std::cout << c;
    EXPECT_TRUE(true);
}
