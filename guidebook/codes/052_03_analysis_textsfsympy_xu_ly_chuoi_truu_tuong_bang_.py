import sympy as sp


def verify_functional_harmonic_limit():
    x = sp.Symbol('x')
    f_prime_0 = sp.Symbol("f'(0)")

    # Define an anonymous function approximated by Taylor Series at x=0
    # Assuming f(0) = 0
    def f(t):
        return f_prime_0 * t + sp.O(t**2)

    n = 5
    sum_expr = sum(f(x / i) for i in range(1, n + 1))

    # Calculate the symbolic limit (1/x) * Sum
    limit_expr = sp.limit(sum_expr / x, x, 0)

    # Known Harmonic number H_5 = 1 + 1/2 + 1/3 + 1/4 + 1/5 = 137/60
    analytic_H_n = sp.Rational(137, 60) * f_prime_0

    assert limit_expr == analytic_H_n
    print(f"Taylor approximated symbolic limit confirmed: {limit_expr}")


verify_functional_harmonic_limit()
