from unittest import TestCase

import fibonacci

table = (0, 1, 1, 2, 3, 5, 8, 13, 21, 34)


class TestFibonacci(TestCase):
    def test_linear_additive_fibonacci(self):
        for i in range(len(table)):
            self.assertEqual(table[i], fibonacci._linear_additive(i))

    def test_linear_multiplicative_fibonacci(self):
        for i in range(len(table)):
            self.assertEqual(table[i], fibonacci._linear_multiplicative(i))

    def test_sublinear_multiplicative_fibonacci(self):
        for i in range(len(table)):
            self.assertEqual(table[i], fibonacci._sublinear_multiplicative(i))

    def test_fast_sublinear_multiplicative_fibonacci(self):
        for i in range(len(table)):
            self.assertEqual(table[i], fibonacci._fast_sublinear_multiplicative(i))

    def test_public_fibonacci(self):
        for i in range(len(table)):
            self.assertEqual(table[i], fibonacci.fibonacci(i))
