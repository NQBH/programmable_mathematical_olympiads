import sympy as sp

def verify_dhgtvt_polynomials():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: DHGTVT VMC2025 Prob. 9 - High-Degree Polynomial Factorization
    """
    x = sp.Symbol('x')

    # 1. Part (a): Verification at roots 1 +/- I
    root = 1 + sp.I
    term1 = root**2024
    term2 = 8 * (root**2004)
    term3 = -127 * (sp.Integer(2)**1005)

    # (1 + I)^4 = -4
    # (1 + I)^2024 = (-4)^506 = 4^506 = 2^1012
    # 8 * (1 + I)^2004 = 8 * (-4)^501 = -8 * 4^501 = -2^3 * 2^1002 = -2^1005
    assert sp.expand(term1 - sp.Integer(2)**1012) == 0
    assert sp.expand(term2 + sp.Integer(2)**1005) == 0
    
    total_P_root = sp.Integer(2)**1012 - sp.Integer(2)**1005 - 127 * (sp.Integer(2)**1005)
    # 2^1012 = 128 * 2^1005
    assert total_P_root == 0, f"P(1 + I) non-zero: {total_P_root}"

    # 2. Part (b): Remainder modulo T(x) = (x + 1)^2 * (x^2 - 2*x + 2)
    # R(x) = (c*x + d) * (x^2 - 2*x + 2)
    # R(-1) = 5*(d - c) == P(-1) = 9 - 127 * 2^1005
    # R'(-1) = 9*c - 4*d == P'(-1) = -18056
    c = sp.Rational(-90244 - 508 * (2**1005), 25)
    d = sp.Rational(-90199 - 1143 * (2**1005), 25)

    eq1 = 5 * (d - c)
    target_eq1 = 9 - 127 * (2**1005)
    assert eq1 == target_eq1, f"Remainder R(-1) mismatch: {eq1} != {target_eq1}"

    eq2 = 9 * c - 4 * d
    target_eq2 = -18056
    assert eq2 == target_eq2, f"Remainder R'(-1) mismatch: {eq2} != {target_eq2}"

    print("Phase 3 Verification Passed:")
    print(f"  P(1 + I) = 2^1012 - 2^1005 - 127*2^1005 == 0 (Divisible by x^2 - 2x + 2)")
    print("  Remainder Coefficients (c, d) rigorously satisfy R(-1) == P(-1) and R'(-1) == P'(-1).")

if __name__ == "__main__":
    verify_dhgtvt_polynomials()
