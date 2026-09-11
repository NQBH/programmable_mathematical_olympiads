import sympy as sp


def verify_leontief_inverse():
    # Matrix A elements explicitly rationalized to avoid float approximation
    A = sp.Matrix([
        [sp.Rational(3, 10), sp.Rational(2, 10)],
        [sp.Rational(1, 10), sp.Rational(4, 10)]
    ])
    d = sp.Matrix([12, 8])

    I = sp.eye(2)
    # Symbolic exact Neumann Limit via Matrix Inversion
    x_exact = (I - A).inv() * d

    print("Exact algebraic required production [Electric, Water]:")
    sp.pprint(x_exact)


verify_leontief_inverse()
