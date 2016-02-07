from unittest import TestCase

import fibonacci


class TestFibonacci(TestCase):

    def test_fibonacci_first_values(self):
        table = (0, 1, 1, 2, 3, 5, 8, 13, 21, 34)
        for i in range(len(table)):
            self.assertEqual(table[i], fibonacci.fibonacci(i))
