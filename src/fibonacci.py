"""
Several implementations of Fibonacci sequence number finders, including a very efficient sublinear pure Python one.
"""


def _multiply_matrix(lhs, rhs):
    return ([lhs[0][0] * rhs[0][0] + lhs[0][1] * rhs[1][0], lhs[0][0] * rhs[0][1] + lhs[0][1] * rhs[1][1]],
            [lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0], lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1]])


def _multiply_triplet(lhs, rhs):
    """
    Special multiplication case that simplifies the 2 by 2 matrix multiplication.
    """
    return lhs[0] * rhs[0] + lhs[1] * rhs[1], lhs[0] * rhs[1] + lhs[1] * rhs[2], lhs[1] * rhs[1] + lhs[2] * rhs[2]


def _matrix_sublinear_power(position):
    """
    Returns [[1, 1], [1, 0]] ** n for n > 0.
    """
    assert position > 0, 'position should be positive'
    base = ((1, 1), (1, 0))
    if position == 1:
        return base
    else:
        matrix = _matrix_sublinear_power(position // 2)
        matrix = _multiply_matrix(matrix, matrix)
        if position % 2 == 1:
            matrix = _multiply_matrix(matrix, base)
        return matrix


def _fast_matrix_sublinear_power(position):
    assert position > 0, 'position should be positive'
    base = (1, 1, 0)
    if position == 1:
        return base
    else:
        triplet = _fast_matrix_sublinear_power(position // 2)
        triplet = _multiply_triplet(triplet, triplet)
        if position % 2 == 1:
            triplet = _multiply_triplet(triplet, base)
        return triplet


def _linear_additive(position):
    assert position >= 0, 'position should be nonnegative'
    if position == 0:
        return 0
    old = 0
    new = 1
    for _ in range(position - 1):
        old, new = new, old + new
    return new


def _linear_multiplicative(position):
    assert position >= 0, 'position should be nonnegative'
    if position == 0:
        return 0
    base = ((1, 1), (1, 0))
    matrix = ((1, 1), (1, 0))
    for _ in range(position - 2):
        matrix = _multiply_matrix(matrix, base)
    return matrix[0][0]


def _sublinear_multiplicative(position):
    assert position >= 0, 'position should be nonnegative'
    if position == 0:
        return 0
    elif position == 1 or position == 2:
        return 1
    return _matrix_sublinear_power(position - 1)[0][0]


def _fast_sublinear_multiplicative(position):
    """
    Returns the n-th Fibonacci number by using a triplet instead of a 2 by 2 matrix.
    """
    assert position >= 0, 'position should be nonnegative'
    if position == 0:
        return 0
    if position == 1 or position == 2:
        return 1
    return _fast_matrix_sublinear_power(position - 1)[0]


def fibonacci(position):
    """
    Returns the n-th Fibonacci number.

    This function's time-complexity is O(lg n).

    :param position: the position of the number in the Fibonacci sequence
    """
    return _fast_sublinear_multiplicative(position)
