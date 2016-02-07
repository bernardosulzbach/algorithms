def _linear_summing(n):
    a = 0
    b = 1
    for i in range(n):
        a, b = b, a + b
    return a


def fibonacci(n):
    """
    Returns the n-th fibonacci number.
    :param n: the position of the number in the Fibonacci sequence
    """
    return _linear_summing(n)
