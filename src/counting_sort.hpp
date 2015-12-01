#pragma once

#include <vector>
#include <algorithm>

namespace algorithms {

    /**
     * Sorts a range using counting sort.
     *
     * O(n) time complexity and O(n) space complexity.
     */
    template<typename RandomAccessIterator, typename Value>
    void counting_sort(RandomAccessIterator begin, RandomAccessIterator end) {
        if (std::distance(begin, end) < 2) return; // Trivially sorted.
        // Find the minimum and the maximum.
        const Value &minimum = *std::min_element(begin, end);
        const Value &maximum = *std::max_element(begin, end);
        std::vector<size_t> buckets(maximum - minimum + 1);
        RandomAccessIterator iterator = begin;
        while (iterator != end) {
            // We subtract minimum from every element in order to determine which bucket it occupies.
            buckets[*iterator - minimum]++;
            iterator++;
        }
        // We reuse the buckets vector to make the cumulative vector.
        for (std::vector<size_t>::size_type i = 1; i != buckets.size(); i++) {
            buckets[i] += buckets[i - 1];
        }
        for (std::vector<size_t>::size_type i = 0; i != buckets.size(); i++) {
            buckets[i]--; // Vectors are zero-indexed.
        }
        std::vector<Value> output(begin, end);
        // Iterate over the input backwards, sorting it.
        while (end != begin) {
            end--;
            size_t index_in_cumulative_vector = *end - minimum;
            // Also decrement the position of the next element.
            size_t index_in_sorted_vector = buckets[index_in_cumulative_vector]--;
            // Remember to add minimum back to our indices.
            output[index_in_sorted_vector] = *end;
        }
        std::copy(output.begin(), output.end(), begin);
    }

}