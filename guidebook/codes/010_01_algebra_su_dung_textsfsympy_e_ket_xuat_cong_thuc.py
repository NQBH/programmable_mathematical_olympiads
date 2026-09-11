import sympy as sp


def verify_parametric_determinant():
    a = sp.Symbol('a', real=True)
    A = sp.Matrix([
        [1, a + 1, a + 2, 0],
        [a + 3, 1, 0, a + 2],
        [a + 2, 0, 1, a + 1],
        [0, a + 2, a + 3, 1]
    ])

    det_A = sp.factor(A.det())
    print(f"Exact algebraic determinant: {det_A}")
    # Solves inequality -4*(a + 1)*(a + 3) > 0
    solution = sp.solve(det_A > 0, a)
    print(f"Domain for positive determinant: {solution}")


verify_parametric_determinant()
