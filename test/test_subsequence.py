from unittest import TestCase

import sequences

fibonacci_table = (0, 1, 1, 2, 3, 5, 8, 13, 21, 34)
lucas_table = (2, 1, 3, 4, 7, 11, 18, 29, 47, 76)


class TestSubsequences(TestCase):
    def test_linear_additive_fibonacci(self):
        for i in range(len(fibonacci_table)):
            self.assertEqual(fibonacci_table[i], sequences._linear_additive(i))

    def test_linear_multiplicative_fibonacci(self):
        for i in range(len(fibonacci_table)):
            self.assertEqual(fibonacci_table[i], sequences._linear_multiplicative(i))

    def test_sublinear_multiplicative_fibonacci(self):
        for i in range(len(fibonacci_table)):
            self.assertEqual(fibonacci_table[i], sequences._sublinear_multiplicative(i))

    def test_fast_sublinear_multiplicative_fibonacci(self):
        for i in range(len(fibonacci_table)):
            self.assertEqual(fibonacci_table[i], sequences._fast_sublinear_multiplicative(i))

    def test_public_fibonacci(self):
        for i in range(len(fibonacci_table)):
            self.assertEqual(fibonacci_table[i], sequences.fibonacci(i))

    def test_public_lucas(self):
        for i in range(len(lucas_table)):
            self.assertEqual(lucas_table[i], sequences.lucas(i))
