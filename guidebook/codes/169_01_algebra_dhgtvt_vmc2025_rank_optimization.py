import sympy as sp

def verify_rank_optimization():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: DHGTVT VMC2025 Prob. 6 - Determinant Annihilation & Rank Invariance
    """
    x = sp.Symbol('x', real=True)
    A = sp.Matrix([
        [x, 2, x, 2],
        [2, x, 2, x],
        [x, x, -1, -1],
        [-1, -1, x, x]
    ])

    # 1. Determinant is identically zero
    det_A = sp.factor(A.det())
    assert det_A == 0, f"Determinant not identically zero: {det_A}"

    # 2. Linear dependence invariant: col1 - col2 - col3 + col4 == 0
    col1 = A.col(0)
    col2 = A.col(1)
    col3 = A.col(2)
    col4 = A.col(3)
    assert (col1 - col2 - col3 + col4) == sp.zeros(4, 1)

    # 3. Analyze all 3x3 minors
    minors = []
    for r in range(4):
        for c in range(4):
            m = sp.factor(A.minor_submatrix(r, c).det())
            if m != 0:
                minors.append(m)

    common_roots = set(sp.solve(minors[0], x))
    for m in minors[1:]:
        common_roots &= set(sp.solve(m, x))

    expected_degenerate = {-1, 2}
    assert common_roots == expected_degenerate, f"Degenerate roots mismatch: {common_roots}"

    # 4. Assert ranks
    assert A.subs(x, -1).rank() == 2
    assert A.subs(x, 2).rank() == 2
    assert A.subs(x, 0).rank() == 3
    assert A.subs(x, 5).rank() == 3

    print("Phase 3 Verification Passed:")
    print("  Determinant det A(x) == 0 identically for all x in R.")
    print("  Degeneracy Locus: All 3x3 minors vanish iff x in {-1, 2}.")
    print("  Rank Classification: rank A(x) = 2 for x in {-1, 2}; rank A(x) = 3 for x not in {-1, 2}.")

if __name__ == "__main__":
    verify_rank_optimization()
