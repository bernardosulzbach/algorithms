# Several implementations of the Fibonacci sequence, including a very efficient sublinear pure Python one.


def _multiply_matrix(a, b):
    return [[a[0][0] * b[0][0] + a[0][1] * b[1][0], a[0][0] * b[0][1] + a[0][1] * b[1][1]],
            [a[1][0] * b[0][0] + a[1][1] * b[1][0], a[1][0] * b[0][1] + a[1][1] * b[1][1]]]


def _multiply_triplet(a, b):
    """
    Special multiplication case that simplifies the 2 by 2 matrix multiplication.
    """
    return a[0] * b[0] + a[1] * b[1], a[0] * b[1] + a[1] * b[2], a[1] * b[1] + a[2] * b[2]


def _matrix_sublinear_power(n):
    """
    Returns [[1, 1], [1, 0]] ** n for n > 0.
    """
    assert n > 0, 'n should be positive'
    base = ((1, 1), (1, 0))
    if n == 1:
        return base
    else:
        matrix = _matrix_sublinear_power(n // 2)
        matrix = _multiply_matrix(matrix, matrix)
        if n % 2 == 1:
            matrix = _multiply_matrix(matrix, base)
        return matrix


def _fast_matrix_sublinear_power(n):
    assert n > 0, 'n should be positive'
    base = (1, 1, 0)
    if n == 1:
        return base
    else:
        triplet = _fast_matrix_sublinear_power(n // 2)
        triplet = _multiply_triplet(triplet, triplet)
        if n % 2 == 1:
            triplet = _multiply_triplet(triplet, base)
        return triplet


def _linear_additive(n):
    assert n >= 0, 'n should be nonnegative'
    a = 0
    b = 1
    for i in range(n):
        a, b = b, a + b
    return a


def _linear_multiplicative(n):
    assert n >= 0, 'n should be nonnegative'
    if n == 0:
        return 0
    base = ((1, 1), (1, 0))
    matrix = ((1, 1), (1, 0))
    for i in range(n - 2):
        matrix = _multiply_matrix(matrix, base)
    return matrix[0][0]


def _sublinear_multiplicative(n):
    assert n >= 0, 'n should be nonnegative'
    if n == 0:
        return 0
    elif n == 1 or n == 2:
        return 1
    return _matrix_sublinear_power(n - 1)[0][0]


def _fast_sublinear_multiplicative(n):
    """
    Returns the n-th Fibonacci number by using a triplet instead of a 2 by 2 matrix.
    """
    assert n >= 0, 'n should be nonnegative'
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1
    return _fast_matrix_sublinear_power(n - 1)[0]


def fibonacci(n):
    """
    Returns the n-th Fibonacci number.

    This function's time-complexity is O(lg n).

    :param n: the position of the number in the Fibonacci sequence
    """
    return _fast_sublinear_multiplicative(n)
