import sympy as sp
from sympy import Eq
from sympy.stats import Binomial, P


def verify_coin_toss_symbolic():
    n, k = sp.symbols('n k', integer=True, positive=True)
    # Part (b) exact probability
    X = Binomial('X', 10, sp.Rational(1, 2))
    exact_prob = P(Eq(X, 5))
    print(f"Exact Binomial Probability P(X=5, n=10): {exact_prob}")

    # Generating function for consecutive runs
    x = sp.Symbol('x')
    k_val = 3
    # F(x) represents the waiting time distribution for length k
    F_x = (x**k_val * (1 - x)) / (1 - 2 * x + x**(k_val + 1))

    print(f"Generating Function for run-length {k_val}:")
    sp.pprint(F_x)


verify_coin_toss_symbolic()
