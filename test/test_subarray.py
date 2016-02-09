from unittest import TestCase

import subarray


class TestSubarray(TestCase):

    def test_find_maximum_subarray(self):
        self.assertTupleEqual((0, 0, 1), subarray.find_maximum_subarray([1], 0, 0))
        self.assertTupleEqual((0, 0, -1), subarray.find_maximum_subarray([-1], 0, 0))
        self.assertTupleEqual((0, 1, 30), subarray.find_maximum_subarray([10, 20], 0, 1))
        self.assertTupleEqual((0, 0, 10), subarray.find_maximum_subarray([10, -20], 0, 1))
        self.assertTupleEqual((1, 4, 65), subarray.find_maximum_subarray([-15, 20, 40, -10, 15], 0, 4))

    def test_find_maximum_subarray_by_kadane(self):
        self.assertTupleEqual((0, 0, 1), subarray.find_maximum_subarray_by_kadane([1], 0, 0))
        self.assertTupleEqual((0, 0, -1), subarray.find_maximum_subarray_by_kadane([-1], 0, 0))
        self.assertTupleEqual((0, 1, 30), subarray.find_maximum_subarray_by_kadane([10, 20], 0, 1))
        self.assertTupleEqual((0, 0, 10), subarray.find_maximum_subarray_by_kadane([10, -20], 0, 1))
        self.assertTupleEqual((1, 4, 65), subarray.find_maximum_subarray_by_kadane([-15, 20, 40, -10, 15], 0, 4))

    def test_find_maximum_subarray_by_divide_and_conquer(self):
        self.assertTupleEqual((0, 0, 1), subarray.find_maximum_subarray_by_divide_and_conquer([1], 0, 0))
        self.assertTupleEqual((0, 0, -1), subarray.find_maximum_subarray_by_divide_and_conquer([-1], 0, 0))
        self.assertTupleEqual((0, 1, 30), subarray.find_maximum_subarray_by_divide_and_conquer([10, 20], 0, 1))
        self.assertTupleEqual((0, 0, 10), subarray.find_maximum_subarray_by_divide_and_conquer([10, -20], 0, 1))
        self.assertTupleEqual((1, 4, 65), subarray.find_maximum_subarray_by_divide_and_conquer([-15, 20, 40, -10, 15], 0, 4))