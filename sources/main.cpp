// Copyright 2020 Nikita Klimov nik179804@gmail.com

#include <iostream>

#include "../../LAB32/include/proc_check.hpp"

int main() {
  proc_check a;
  a.countDirect();
  std::cout << a;
  proc_check b;
  b.countReverse();
  std::cout << b;
  proc_check c;
  c.countRandom();
  std::cout << c;
  return 0;
}
