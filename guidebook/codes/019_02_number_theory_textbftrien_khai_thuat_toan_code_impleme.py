import sympy as sp
from sympy import Eq
from sympy.stats import Hypergeometric, P


def verify_prime_probability():
    n, m, k = 100, 10, 3

    # Exact prime counting without explicit sieving
    primes_count = sp.primepi(n)

    # Hypergeometric distribution: N elements, success states, draws
    X = Hypergeometric('X', n, primes_count, m)

    # Exact algebraic probability of drawing exactly k primes
    exact_prob = P(Eq(X, k))

    print(f"Number of primes up to {n}: {primes_count}")
    print(f"Exact Probability P(X={k}): {exact_prob}")


verify_prime_probability()
