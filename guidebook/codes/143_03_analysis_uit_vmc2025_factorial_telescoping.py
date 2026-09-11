import sympy as sp

def verify_telescoping_series():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: UIT VMC2025 Prob. 14 & 17 - Exact Factorial & Nonlinear Telescoping
    """
    i = sp.Symbol('i', integer=True)

    # 1. Verification of polynomial factorization identity
    target_poly = i**4 + 10*i**3 + 35*i**2 + 50*i + 23
    factor_poly = (i + 1) * (i + 2) * (i + 3) * (i + 4) - 1
    assert sp.expand(factor_poly - target_poly) == 0, "Factorial polynomial identity mismatch"

    # 2. Exact sum of telescoping series: sum_{i=0}^oo (1/i! - 1/(i+4)!)
    # Telescoping sum yields 1/0! + 1/1! + 1/2! + 1/3! = 1 + 1 + 1/2 + 1/6 = 8/3
    term_0 = sp.Rational(1, sp.factorial(0))
    term_1 = sp.Rational(1, sp.factorial(1))
    term_2 = sp.Rational(1, sp.factorial(2))
    term_3 = sp.Rational(1, sp.factorial(3))
    exact_limit = term_0 + term_1 + term_2 + term_3
    assert exact_limit == sp.Rational(8, 3), f"Expected 8/3, got {exact_limit}"

    # 3. Verification of Sylvester's recurrence telescoping identity
    # x_{n+1} = x_n^2 - x_n + 1 => x_{n+1} - 1 = x_n * (x_n - 1)
    # 1/(x_n - 1) - 1/(x_{n+1} - 1) = 1/x_n
    x_n = sp.Symbol('x_n')
    x_next_minus_1 = x_n * (x_n - 1)
    telescope_diff = 1 / (x_n - 1) - 1 / x_next_minus_1
    simplified_diff = sp.simplify(telescope_diff)
    assert simplified_diff == 1 / x_n, "Sylvester telescoping identity failed"

    print("Phase 3 Verification Passed:")
    print(f"  Polynomial Identity: {factor_poly} == {target_poly}")
    print(f"  Factorial Series Exact Limit: {exact_limit}")
    print("  Sylvester Telescoping Invariant: 1/(x_n - 1) - 1/(x_{n+1} - 1) == 1/x_n")

if __name__ == "__main__":
    verify_telescoping_series()
