import sympy as sp


def verify_rank_nullity():
    lam = sp.Symbol('lambda')
    M = sp.Matrix([
        [1, lam, -1, 2],
        [2, -1, lam, 5],
        [1, 10, -6, 1]
    ])

    # Analyze the specific critical point
    M_3 = M.subs(lam, 3)
    null_basis = M_3.nullspace()
    col_basis = M_3.columnspace()

    print(f"Ker(f) Basis (Lambda=3): {null_basis}")
    print(f"Im(f) Basis (Lambda=3): {col_basis}")


verify_rank_nullity()
