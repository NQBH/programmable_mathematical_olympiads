import sympy as sp

def verify_marble_generating_function():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: UIT VMC2025 Combinatorics - Generating Function Partial Fractions
    """
    x = sp.Symbol('x')
    
    # 1. Product of Generating Functions
    G_red = 1 / (1 - x**2)
    G_orange = 1 / (1 - x**7)
    G_yellow = (1 - x**7) / (1 - x)
    G_green = (1 - x**5) / (1 - x)

    G = G_red * G_orange * G_yellow * G_green
    G_simplified = sp.simplify(G)

    expected_simplified = (1 - x**5) / ((1 - x**2) * (1 - x)**2)
    assert sp.simplify(G_simplified - expected_simplified) == 0

    # 2. Partial Fraction Decomposition
    pfrac = sp.apart(G_simplified, x)

    # 3. Series expansion check up to x^20
    series_exp = sp.series(G_simplified, x, 0, 20)
    for n in range(2, 20):
        coeff_n = series_exp.coeff(x, n)
        sign = 1 if n % 2 == 0 else -1
        expected_coeff = (10 * n - 5 + sign) // 4
        assert coeff_n == expected_coeff, f"Mismatch at n={n}: {coeff_n} != {expected_coeff}"

    # 4. Target n = 2025
    n_target = 2025
    target_coeff = (10 * n_target - 5 - 1) // 4
    assert target_coeff == 5061

    print("Phase 3 Verification Passed:")
    print(f"  Algebraic Cancellation: Factor (1 - x^7) cancels completely.")
    print(f"  Partial Fraction Expansion: {pfrac}")
    print(f"  Closed-form Coefficient: [x^n] G(x) = (10n - 5 + (-1)^n) / 4 for n >= 2.")
    print(f"  Target Evaluation: [x^2025] G(x) = {target_coeff} rigorously confirmed.")

if __name__ == "__main__":
    verify_marble_generating_function()
