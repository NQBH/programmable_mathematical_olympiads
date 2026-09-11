import sympy as sp

def verify_nonlinear_recurrence():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: DHGTVT VMC2025 Prob. 7 - Fixed-Point Algebraic Resolution
    """
    L = sp.Symbol('L', positive=True)
    sqrt5 = sp.sqrt(5)

    # 1. Fixed-point equation: L - sqrt(5) = 2*L / sqrt(L^2 - 4)
    # Squaring leads to polynomial: (L - sqrt(5))^2 * (L^2 - 4) - 4*L^2 = 0
    poly = (L - sqrt5)**2 * (L**2 - 4) - 4 * L**2
    expanded_poly = sp.expand(poly)
    roots = sp.solve(poly, L)

    # Find the real root strictly greater than 2 + sqrt(5)
    lower_bound = 2 + sqrt5
    num_lower_bound = float(lower_bound.evalf())
    valid_roots = []

    for r in roots:
        r_eval = complex(r.evalf())
        if abs(r_eval.imag) < 1e-9 and r_eval.real > num_lower_bound:
            valid_roots.append(r)

    assert len(valid_roots) == 1, f"Expected exactly 1 valid root, found {len(valid_roots)}"
    limit_root = valid_roots[0]
    assert sp.simplify(limit_root - 2 * sqrt5) == 0, f"Root mismatch: expected 2*sqrt(5), got {limit_root}"

    # 2. Verify derivative contraction: f'(x) = -8 / (x^2 - 4)^(3/2)
    x = sp.Symbol('x', positive=True)
    f = sqrt5 + 2 * x / sp.sqrt(x**2 - 4)
    f_prime = sp.diff(f, x)
    f_prime_simplified = sp.simplify(f_prime)
    expected_f_prime = -8 / (x**2 - 4)**(sp.Rational(3, 2))
    assert sp.simplify(f_prime_simplified - expected_f_prime) == 0, "Derivative formula mismatch"

    # Evaluate contraction factor at lower bound x = 2 + sqrt(5)
    max_derivative_mag = abs(float(f_prime.subs(x, lower_bound).evalf()))
    assert max_derivative_mag < 0.2, f"Contraction factor must be strictly < 1, got {max_derivative_mag}"

    print("Phase 3 Verification Passed:")
    print(f"  Fixed-Point Polynomial: {expanded_poly} = 0")
    print(f"  Unique Root > 2+sqrt(5): L = {limit_root} = {float(limit_root.evalf()):.10f}")
    print(f"  Contraction Bound |f'(2+sqrt(5))| = {max_derivative_mag:.6f} < 1")

if __name__ == "__main__":
    verify_nonlinear_recurrence()
