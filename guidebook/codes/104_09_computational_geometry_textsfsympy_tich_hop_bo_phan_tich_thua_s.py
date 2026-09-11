import sympy as sp


def verify_coprime_divisors():
    a = 360  # Example 360 = 2^3 * 3^2 * 5^1

    factors = sp.factorint(a)

    num = sp.prod([2 * exponent + 1 for exponent in factors.values()])
    den = sp.prod([(exponent + 1)**2 for exponent in factors.values()])

    prob_irreducible = sp.Rational(num, den)
    print(f"Prime factorization of {a}: {factors}")
    print(f"Exact Probability of irreducible fraction: {prob_irreducible}")


verify_coprime_divisors()
