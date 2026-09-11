import sympy as sp

def verify_implicit_integral():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: UIT VMC2025 Prob. 16 - Implicit Curve Differential Substitution
    """
    z = sp.Symbol('z', positive=True)

    # 1. Integration limits for z when x in [0, 2024]
    # At x = 0: z^4 = 2025 => z = 2025^(1/4) = sqrt(45) = 3*sqrt(5)
    z_lower = 3 * sp.sqrt(5)
    # At x = 2024: z^4 + 2024*z^2 - 2025 = 0 => (z^2 - 1)(z^2 + 2025) = 0 => z = 1
    z_upper = 1

    # 2. Substitution: x = (2025 - z^4) / z^2 = 2025/z^2 - z^2
    # dx = (-4050/z^3 - 2*z) dz = -2*(2025/z^3 + z) dz
    # Integral = \int_{3*sqrt(5)}^1 z^3 * [-2*(2025/z^3 + z)] dz
    #          = \int_1^{3*sqrt(5)} 2 * (2025 + z^4) dz
    integrand_z = 2 * (2025 + z**4)
    exact_integral = sp.integrate(integrand_z, (z, z_upper, z_lower))

    # 3. Expected closed-form expression
    expected_form = 14580 * sp.sqrt(5) - sp.Rational(20252, 5)
    diff = sp.simplify(exact_integral - expected_form)
    assert diff == 0, f"Symbolic integral deviation: {diff}"

    num_val = float(exact_integral.evalf())
    assert abs(num_val - 28551.4711119469) < 1e-8

    print("Phase 3 Verification Passed:")
    print(f"  Transformed Integrand: {integrand_z}")
    print(f"  Exact Symbolic Solution: {exact_integral}")
    print(f"  Numerical Value: {num_val:.10f}")

if __name__ == "__main__":
    verify_implicit_integral()
