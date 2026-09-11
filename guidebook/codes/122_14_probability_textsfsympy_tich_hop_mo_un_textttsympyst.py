import sympy as sp
from sympy import Eq
from sympy.stats import Binomial, P


def verify_binomial_toss():
    n, k = 10, 5
    # Define random variable X ~ Binomial(n, 1/2)
    X = Binomial('X', n, sp.Rational(1, 2))

    # Evaluate exact probability
    prob_exact = P(Eq(X, k))

    print(f"Symbolic evaluation for P(X={k} out of {n}): {prob_exact}")


verify_binomial_toss()
