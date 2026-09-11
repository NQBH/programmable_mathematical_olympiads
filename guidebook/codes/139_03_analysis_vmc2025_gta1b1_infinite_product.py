import sympy as sp

def verify_infinite_product():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: VMC2025GTA1B1 - Infinite Product Convergence & Positivity Proof
    """
    k = sp.Symbol('k', integer=True, positive=True)
    pi = sp.pi

    # 1. Verification of the bounding p-series sum
    series_sum = sp.summation(1 / (k + 1)**2, (k, 1, sp.oo))
    expected_sum = (pi**2 / 6) - 1
    assert sp.simplify(series_sum - expected_sum) == 0, "p-series sum mismatch"

    # 2. Bounding constant for log(1 - t) >= -c*t on t in (0, pi/4]
    # For t <= pi/4, -log(1 - pi/4) / (pi/4) provides an exact lower slope
    t0 = pi / 4
    c_slope = -sp.log(1 - t0) / t0
    
    # 3. Exact evaluation via Euler reflection / sine product formula
    # prod_{m=1}^oo (1 - z^2 / m^2) = sin(pi*z) / (pi*z)
    # Here z = sqrt(pi). The term m=1 is (1 - pi), so:
    # prod_{m=2}^oo (1 - pi / m^2) = sin(pi*sqrt(pi)) / (pi*sqrt(pi)*(1 - pi))
    z = sp.sqrt(pi)
    exact_limit = sp.sin(pi * z) / (pi * z * (1 - pi))
    num_limit = float(exact_limit.evalf())

    assert num_limit > 0.05, f"Limit must be strictly positive, got {num_limit}"
    assert abs(num_limit - 0.0549689476) < 1e-6, "Numerical limit deviation"

    print("Phase 3 Verification Passed:")
    print(f"  Sum of 1/(k+1)^2: {series_sum} = {float(series_sum.evalf()):.6f}")
    print(f"  Euler Sine Product Exact Form: {exact_limit}")
    print(f"  Analytical Limit Value: {num_limit:.10f} > 0")

if __name__ == "__main__":
    verify_infinite_product()
