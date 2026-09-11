import sympy as sp

def verify_power_mean():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: VMC2025GTA2 / GTB2 - Power Mean Monotonicity & Information Divergence
    """
    x = sp.Symbol('x', positive=True)
    a1, a2, a3 = 30, 4, 2025

    # 1. Power mean definition and logarithmic transformation
    f = ((sp.Integer(a1)**x + sp.Integer(a2)**x + sp.Integer(a3)**x) / 3)**(1 / x)
    ln_f = (1 / x) * sp.log((sp.Integer(a1)**x + sp.Integer(a2)**x + sp.Integer(a3)**x) / 3)

    # 2. Limit as x -> 0+ via L'Hopital / series expansion
    limit_zero = sp.limit(f, x, 0)
    expected_limit = sp.cbrt(a1 * a2 * a3)
    assert sp.simplify(limit_zero - expected_limit) == 0, f"Limit mismatch: {limit_zero} != {expected_limit}"

    # 3. Monotonicity proof via Jensen's inequality / KL Divergence:
    # Let phi(t) = t * log(t). phi''(t) = 1/t > 0 for all t > 0 (strictly convex).
    t = sp.Symbol('t', positive=True)
    phi = t * sp.log(t)
    phi_double_prime = sp.diff(phi, t, 2)
    assert sp.simplify(phi_double_prime - 1/t) == 0, "Convexity check failed"
    
    # By strict Jensen's inequality:
    # (1/3) * sum(phi(y_i)) > phi((1/3) * sum(y_i)) for distinct y_i = a_i^x
    # Dividing by (1/3) * sum(y_i) proves that d/dx [ln f(x)] > 0 strictly.
    y = [float(a1), float(a2), float(a3)]
    for test_x in [0.1, 1.0, 5.0]:
        y_x = [val**test_x for val in y]
        mean_y = sum(y_x) / 3.0
        jensen_lhs = sum(val * sp.log(val) for val in y_x) / 3.0
        jensen_rhs = mean_y * sp.log(mean_y)
        gap = float(jensen_lhs - jensen_rhs)
        assert gap > 0, f"Strict convexity gap violated at x={test_x}: {gap}"

    print("Phase 3 Verification Passed:")
    print(f"  Exact Limit x -> 0+: {limit_zero} = {float(limit_zero.evalf()):.8f}")
    print(f"  Strict Convexity phi''(t) = {phi_double_prime} > 0 implies f'(x) > 0 unconditionally.")

if __name__ == "__main__":
    verify_power_mean()
