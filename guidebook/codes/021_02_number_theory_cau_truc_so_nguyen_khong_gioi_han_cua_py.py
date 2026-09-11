import sympy as sp
import math


def verify_hypergeometric_parity():
    a, b = 1, 1000
    n, k = 50, 25

    E = (b // 2) - ((a - 1) // 2)
    O = (b - a + 1) - E

    # Exact integer combinations
    combinations_E = math.comb(E, k)
    combinations_O = math.comb(O, n - k)
    total_combinations = math.comb(E + O, n)

    exact_prob = sp.Rational(
        combinations_E * combinations_O, total_combinations)
    print(f"Exact P(k={k} evens out of n={n}): {exact_prob}")


verify_hypergeometric_parity()
