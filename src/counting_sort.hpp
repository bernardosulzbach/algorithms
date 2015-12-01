#pragma once

#include <vector>
#include <algorithm>

namespace algorithms {

    /**
     * Sorts the elements in the range [first, last) in nondecreasing order using counting sort. This algorithm has O(n)
     * time complexity and O(n) space complexity. These elements must have integer type.
     *
     * The order of equal elements is guaranteed to be preserved.
     *
     * Cannot handle more than 4,294,967,295 elements.
     */
    template<typename RandomAccessIterator, typename Value>
    void counting_sort(RandomAccessIterator begin, RandomAccessIterator end) {
        if (std::distance(begin, end) < 2) return; // Trivially sorted.
        if (std::distance(begin, end) > 4294967295) return; // Cannot sort.
        // Find the minimum and the maximum.
        const Value &minimum = *std::min_element(begin, end);
        const Value &maximum = *std::max_element(begin, end);
        std::vector<uint32_t> vector(maximum - minimum + 1);
        RandomAccessIterator iterator = begin;
        // Count repetitions.
        while (iterator != end) {
            // We subtract minimum from every element in order to determine which bucket it occupies.
            vector[*iterator - minimum]++;
            iterator++;
        }
        // Reuse the vector to determine where each repetition ends.
        for (std::vector<uint32_t>::size_type i = 1; i != vector.size(); i++) {
            vector[i] += vector[i - 1];
        }
        // As we need indices, not frequencies, subtract one from each counter.
        for (std::vector<uint32_t>::size_type i = 0; i != vector.size(); i++) {
            vector[i]--;
        }
        std::vector<Value> output((unsigned long) std::distance(begin, end)); // Will never be negative, this is safe.
        // Iterate over the input backwards, sorting it.
        while (end != begin) {
            end--;
            const Value index_in_cumulative_vector = *end - minimum;
            // Also decrement the position of the next element.
            const Value index_in_sorted_vector = vector[index_in_cumulative_vector]--;
            output[index_in_sorted_vector] = *end;
        }
        std::copy(output.begin(), output.end(), begin);
    }

}