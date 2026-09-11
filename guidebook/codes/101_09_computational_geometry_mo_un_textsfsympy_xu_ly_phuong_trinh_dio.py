import sympy as sp


def verify_perimeter_diophantine():
    n = 100

    # Exact sample space for positive integers
    sample_space = n - 1

    # Boolean indicator evaluated as integer for square configuration
    is_even = 1 if n % 2 == 0 else 0
    square_ways = is_even

    prob_square = sp.Rational(square_ways, sample_space)
    print(f"P(Square) for n={n}: {prob_square}")

    prob_rectangle = sp.Rational(sample_space - square_ways, sample_space)
    print(f"P(Rectangle | a != b) for n={n}: {prob_rectangle}")


verify_perimeter_diophantine()
