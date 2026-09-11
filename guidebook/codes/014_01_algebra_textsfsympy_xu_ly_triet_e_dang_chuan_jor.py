import sympy as sp


def verify_jordan_sine():
    x, y = sp.symbols('x y', real=True)
    A = sp.Matrix([
        [x, y],
        [0, x]
    ])

    # SymPy evaluates transcendental functions on Jordan blocks analytically
    sin_A = sp.sin(A)
    print("Symbolic Sine Matrix:")
    sp.pprint(sin_A)


verify_jordan_sine()
