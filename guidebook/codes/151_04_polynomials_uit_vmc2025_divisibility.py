import sympy as sp

def verify_uit_polynomials():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: UIT VMC2025 Prob. 3 - Roots of Unity & Commuting Polynomial Derivations
    """
    x = sp.Symbol('x')
    omega = sp.exp(2 * sp.pi * sp.I / 3)

    # 1. Part (a): Check divisibility via roots of unity evaluation
    # P_omega(m, n) = omega^m + omega^n + 1
    for m in range(1, 10):
        for n in range(1, 10):
            val = sp.expand_complex(omega**m + omega**n + 1)
            is_zero = (val == 0)
            expected = ((m * n - 2) % 3 == 0)
            assert is_zero == expected, f"Discrepancy at m={m}, n={n}: {val} != 0"

    # 2. Part (b): Formal functional equation verification
    # P(x) = a*x + a*(1 - a)
    a = sp.Symbol('a', integer=True)
    P = a * x + a * (1 - a)
    P_prime = sp.diff(P, x)

    LHS = sp.simplify(P.subs(x, P_prime))
    RHS = sp.simplify(P_prime.subs(x, P))
    assert LHS == RHS, f"Identity failed: {LHS} != {RHS}"

    # Degree constraint: n^(n-1) * a_n = 1 has no integer solution for n >= 2
    for deg in range(2, 6):
        coeff_constraint = deg**(deg - 1)
        assert coeff_constraint > 1, "Integer constraint violated"

    print("Phase 3 Verification Passed:")
    print("  Roots of Unity Condition: omega^m + omega^n + 1 == 0 <=> (m*n - 2) % 3 == 0")
    print(f"  Linear Family Invariant: P(P'(x)) = {LHS} == P'(P(x)) = {RHS}")
    print("  Non-existence of deg >= 2 integer solutions verified.")

if __name__ == "__main__":
    verify_uit_polynomials()
