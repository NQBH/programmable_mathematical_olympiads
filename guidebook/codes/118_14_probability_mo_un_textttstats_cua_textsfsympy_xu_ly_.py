import sympy as sp
from sympy import Eq
from sympy.stats import Die, density, P


def verify_simultaneous_dice():
    X, Y = Die('X', 6), Die('Y', 6)

    # Exact symbolic evaluation of algebraic convolution
    prob_sum_7 = P(Eq(X + Y, 7))
    print(f"P(X + Y = 7) = {prob_sum_7}")

    # Parity verification
    prob_same_parity = P(Eq(X % 2, Y % 2))
    print(f"P(Same Parity) = {prob_same_parity}")


verify_simultaneous_dice()
