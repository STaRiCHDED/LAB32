// Copyright 2020 Nikita Klimov nik179804@gmail.com

#ifndef INCLUDE_PROC_CHECK_HPP_
#define INCLUDE_PROC_CHECK_HPP_

#include <ctime>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const int kylo = 1024;

class proc_check {
  const std::vector<int> cache_size = {64 * kylo, 256 * kylo, 6 * 1024 * kylo};
  int k;
  std::string travel_variant;
  std::vector<int> size_buf;
  std::vector<double> result_of_experiments;

 public:
  proc_check();
  std::stringstream getExperiment(size_t num_exp) const;
  std::string getTravel() const;
  size_t getCountBuf() const;
  void countDirect();
  void countReverse();
  void countRandom();
  friend std::ostream& operator<<(std::ostream& out, const proc_check& a);
};

#endif  // INCLUDE_PROC_CHECK_HPP_
