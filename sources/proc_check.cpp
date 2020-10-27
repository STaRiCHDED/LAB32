// Copyright 2020 Nikita Klimov nik179804@gmail.com

#include "../../LAB32/include/proc_check.hpp"

#include <algorithm>
#include <iomanip>
#include <random>
#include <string>

const int thousand = 1000;
const int sixteen = 16;

proc_check::proc_check() {
  for (int size = 1.0 / 2 * cache_size[0]; size <= 3.0 / 2 * cache_size[2];
       size *= 2) {
    size_buf.push_back(size);
  }
}

size_t proc_check::getCountBuf() const { return size_buf.size(); }

void proc_check::countDirect() {
  travel_variant = "direction";
  for (const int& i : size_buf) {
    int* arr = new int[static_cast<int>(i / 4.0)];
    for (size_t j = 0; j < i / 4.0; j += sixteen) {
      k = arr[j];
    }
    int start_time = clock();
    for (size_t num = 0; num < thousand; ++num) {
      for (size_t j = 0; j < i / 4.0; j += sixteen) {
        k = arr[j];
      }
    }
    int end_time = clock();
    result_of_experiments.push_back(static_cast<double>(end_time - start_time) /
                                    CLOCKS_PER_SEC * thousand);
    delete[] arr;
  }
}

void proc_check::countReverse() {
  travel_variant = "reverse";
  for (const int& i : size_buf) {
    int* arr = new int[static_cast<int>(i / 4.0)];
    for (size_t j = i / 4.0; j > 0; j -= sixteen) {
      k = arr[j];
    }
    int start_time = clock();
    for (size_t num = 0; num < thousand; ++num) {
      for (size_t j = i / 4.0; j > 0; j -= sixteen) {
        k = arr[j];
      }
    }
    int end_time = clock();
    result_of_experiments.push_back(static_cast<double>(end_time - start_time) /
                                    CLOCKS_PER_SEC * thousand);
    delete[] arr;
  }
}

void proc_check::countRandom() {
  travel_variant = "random";
  for (const int& i : size_buf) {
    int* arr = new int[static_cast<int>(i / 4.0)];
    std::vector<int> index_of_blocks;
    for (size_t j = 0; j < i / 4.0; j += sixteen) {
      index_of_blocks.push_back(j);
      k = arr[j];
    }
    auto rng = std::default_random_engine{};
    std::shuffle(index_of_blocks.begin(), index_of_blocks.end(), rng);

    int start_time = clock();
    for (size_t num = 0; num < thousand; ++num) {
      for (auto index : index_of_blocks) {
        k = arr[index];
      }
    }
    int end_time = clock();
    result_of_experiments.push_back(static_cast<double>(end_time - start_time) /
                                    CLOCKS_PER_SEC * thousand);
    delete[] arr;
  }
}

std::stringstream proc_check::getExperiment(size_t num_exp) const {
  std::stringstream out;
  out << "\t- experiment:\n"
      << "\t\tnumber: " << num_exp + 1 << "\n"
      << "\t\tinput_data:\n"
      << "\t\t\tbuffer_size: " << size_buf[num_exp] << " B"
      << "\n"
      << "\t\tresults:\n"
      << "\t\t\tduration: " << result_of_experiments[num_exp] << "ms" << '\n';
  return out;
}

std::string proc_check::getTravel() const { return travel_variant; }

std::ostream& operator<<(std::ostream& out, const proc_check& a) {
  out << "investigation:\n"
      << "\ttravel_order: " << a.getTravel() << "\n";
  for (size_t i = 0; i < a.getCountBuf(); ++i) out << a.getExperiment(i).str();
  out << "\n";
  return out;
}
