import sympy as sp


def verify_circulant_spectrum():
    x = sp.Symbol('x', real=True)
    A = sp.Matrix([
        [x, 2022, 2023],
        [2022, 2023, x],
        [2023, x, 2022]
    ])

    det_A = A.det()
    roots = sp.solve(det_A, x)

    print(f"Determinant factored: {sp.factor(det_A)}")
    print(f"Real singularity points: {roots}")


verify_circulant_spectrum()
