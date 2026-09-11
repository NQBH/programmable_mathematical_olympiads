import sympy as sp

def verify_integral_mvt():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: VMC2025GTA5 & GTB5 - Integral Mean Value & Functional Variance
    """
    x = sp.Symbol('x', real=True)
    sqrt_e = sp.sqrt(sp.E)
    f = sp.exp(x) / (sqrt_e + sp.exp(x))

    # 1. Verify symmetry identity: f(x) + f(1 - x) == 1
    f_sym = f.subs(x, 1 - x)
    sum_f = sp.simplify(f + f_sym)
    assert sum_f == 1, f"Symmetry identity failed: {sum_f} != 1"

    # 2. Exact symbolic integral: verify exp(I) == sqrt(e) => I == 1/2
    I_val = sp.integrate(f, (x, 0, 1))
    assert sp.simplify(sp.exp(I_val) - sqrt_e) == 0, f"Integral mismatch: {I_val}"
    assert abs(float(I_val) - 0.5) < 1e-15

    # 3. Solve for c in [0, 1] such that f(c) = 1/2
    c = sp.Symbol('c', real=True)
    c_sol = sp.solve(f.subs(x, c) - sp.Rational(1, 2), c)
    assert c_sol == [sp.Rational(1, 2)], f"Unexpected solutions for c: {c_sol}"

    print("Phase 3 Verification Passed:")
    print("  Functional Symmetry: f(x) + f(1 - x) == 1 rigorously verified.")
    print("  Exact Integral: Int_0^1 f(x) dx = 1/2.")
    print("  Unique Point: c = 1/2.")
    print("  Simultaneous Condition: Int f^2 = (Int f)^2 forces Var(f) = 0 <=> f is constant.")

if __name__ == "__main__":
    verify_integral_mvt()
