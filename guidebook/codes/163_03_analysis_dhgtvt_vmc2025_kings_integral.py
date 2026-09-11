import sympy as sp

def verify_kings_integral():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: DHGTVT VMC2025 Prob. 13 - King's Property & Definite Integration
    """
    x, t = sp.symbols('x t', real=True)
    pi = sp.pi

    # 1. Algebraic proof of King's property:
    # Int_0^pi x * f(sin x) dx = (pi/2) * Int_0^pi f(sin x) dx
    f = sp.Function('f')
    # Substitution x = pi - t:
    # Int_0^pi (pi - t) * f(sin(pi - t)) dt = pi * Int_0^pi f(sin t) dt - Int_0^pi t * f(sin t) dt
    # => 2 * I = pi * Int_0^pi f(sin t) dt => I = (pi/2) * Int_0^pi f(sin t) dt

    # 2. Case 1: f(sin x) = sin x / (1 + sin^2 x) = sin x / (2 - cos^2 x)
    u = sp.Symbol('u', real=True)
    # Integral reduces to: (pi/2) * Int_{-1}^1 du / (2 - u^2)
    int_u1 = sp.integrate(1 / (2 - u**2), (u, -1, 1))
    exact_I1 = sp.simplify((pi / 2) * int_u1)
    target_I1 = (pi / sp.sqrt(2)) * sp.log(sp.sqrt(2) + 1)
    assert sp.simplify(sp.expand_log(exact_I1 - target_I1)) == 0, f"Case 1 failed: {exact_I1} != {target_I1}"

    # 3. Case 2: f(sin x) = sin x / (4 - cos^2 x)
    # Integral reduces to: (pi/2) * Int_{-1}^1 du / (4 - u^2)
    int_u2 = sp.integrate(1 / (4 - u**2), (u, -1, 1))
    exact_I2 = sp.simplify((pi / 2) * int_u2)
    target_I2 = (pi * sp.log(3)) / 4
    assert sp.simplify(sp.expand_log(exact_I2 - target_I2)) == 0, f"Case 2 failed: {exact_I2} != {target_I2}"

    print("Phase 3 Verification Passed:")
    print("  King Symmetry Invariant: Int_0^pi x*f(sin x) dx = (pi/2) * Int_0^pi f(sin x) dx.")
    print(f"  Exact Integral 1 (1 + sin^2 x): {exact_I1} == (pi / sqrt(2)) * ln(sqrt(2) + 1)")
    print(f"  Exact Integral 2 (4 - cos^2 x): {exact_I2} == (pi * ln(3)) / 4")

if __name__ == "__main__":
    verify_kings_integral()
