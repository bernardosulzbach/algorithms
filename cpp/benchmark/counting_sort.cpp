#include "counting_sort.hpp"

#include <chrono>
#include <iostream>
#include <iomanip>

void write_benchmark_result(std::string name, uint32_t size, uint32_t value_count, double result) {
    std::cout << std::setw(32) << std::left << name + " for ";
    std::cout << std::setw(8) << std::right << size;
    std::cout << " values from the range [0, ";
    std::cout << std::setw(8) << std::right << value_count;
    std::cout << ") took ";
    std::cout << std::scientific << result << " seconds.\n";
}

int main() {
    std::vector<uint32_t> powers = {10, 100, 1000, 10000, 100000, 1000000};
    for (uint32_t size : powers) {
        for (uint32_t value_count : powers) {
            std::vector<int> random_vector;
            for (int i = 0; i < size; i++) random_vector.push_back(rand() % value_count);
            std::vector<int> copy(random_vector);

            std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
            algorithms::counting_sort<std::vector<int>::iterator, int>(copy.begin(), copy.end());
            std::chrono::duration<double> counting_sort = std::chrono::system_clock::now() - start;
            write_benchmark_result("algorithms::counting_sort", size, value_count, counting_sort.count());

            copy.swap(random_vector);
            start = std::chrono::system_clock::now();
            std::sort(random_vector.begin(), random_vector.end());
            std::chrono::duration<double> standard_sort = std::chrono::system_clock::now() - start;
            write_benchmark_result("std::sort", size, value_count, standard_sort.count());
        }
    }
}
