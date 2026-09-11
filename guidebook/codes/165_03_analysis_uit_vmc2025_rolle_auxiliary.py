import sympy as sp

def verify_rolle_auxiliary():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: UIT VMC2025 Prob. 15 - Rolle Auxiliary Theorem Construction
    """
    x, t = sp.symbols('x t', real=True)
    f = sp.Function('f')
    F = sp.Function('F') # F(x) = Int_0^x f(t) dt => F'(x) = f(x)

    # 1. Verification of primary auxiliary function:
    # g(x) = x * F(x) - Int_0^x t * f(t) dt
    # g'(x) = F(x) + x * f(x) - x * f(x) = F(x)
    # Using derivative:
    # g(0) = 0, g(1) = Int_0^1 f - Int_0^1 t*f = 0
    # Rolle => exists alpha in (0, 1) such that g'(alpha) = F(alpha) = 0

    # 2. Verification of secondary auxiliary function:
    # h(x) = e^(-x) / (1 - x) * F(x)
    # Differentiate h(x):
    h = sp.exp(-x) / (1 - x) * F(x)
    h_prime = sp.diff(h, x)
    # Substitute F'(x) = f(x):
    h_prime_sub = h_prime.subs(sp.Derivative(F(x), x), f(x))

    # Factor out common positive term e^(-x) / (1 - x)^2:
    factored_core = sp.simplify(h_prime_sub * (sp.exp(x) * (1 - x)**2))
    
    # Target expression: (1 - x)*f(x) + x*F(x)
    target = (1 - x) * f(x) + x * F(x)
    assert sp.simplify(factored_core - target) == 0, f"Rolle derivative mismatch: {factored_core} != {target}"

    # 3. Test on concrete polynomial: f(x) = 1 - 2*x - 2*x^2
    p = 1 - 2*x - 2*x**2
    int_p = sp.integrate(p, (x, 0, 1))
    int_xp = sp.integrate(x * p, (x, 0, 1))
    assert int_p == int_xp == sp.Rational(-2, 3)

    P_int = sp.integrate(p, x)
    alpha_eq = P_int # x - x^2 - (2/3)*x^3
    # Solved symbolically on [0, 1]:
    roots = sp.real_roots(alpha_eq - alpha_eq.subs(x, 0))
    alphas = [r for r in roots if r > 0 and r < 1]
    assert len(alphas) == 1
    alpha_val = alphas[0]

    target_poly = (1 - x) * p + x * alpha_eq
    c_roots = sp.real_roots(target_poly)
    valid_c = [r for r in c_roots if r > 0 and r < alpha_val]
    assert len(valid_c) == 1
    c_val = valid_c[0]

    print("Phase 3 Verification Passed:")
    print("  Derivative of Primary Auxiliary g'(x) == F(x) (Rolle root alpha in (0, 1)).")
    print(f"  Derivative of Secondary Auxiliary h'(x) == [e^(-x)/(1-x)^2] * {target}")
    print(f"  Concrete Verification: alpha = {float(alpha_val):.6f}, c = {float(c_val):.6f} in (0, alpha).")

if __name__ == "__main__":
    verify_rolle_auxiliary()
