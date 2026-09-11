import sympy as sp


def verify_taylor_expansion():
    x = sp.Symbol('x')
    a = sp.Symbol('a')

    # Polynomial of degree 3
    P_x = 2 * x**3 - 5 * x**2 + x - 9

    # Exact algebraic Taylor series around point 'a'
    # The remainder term O((x-a)^4) automatically vanishes
    taylor_poly = sp.series(P_x, x, a, n=4).removeO()

    print(f"Original Polynomial: {P_x}")
    print(f"Exact Taylor Shift around a: {taylor_poly}")
    print(f"Equivalence verified: {sp.simplify(P_x - taylor_poly) == 0}")


verify_taylor_expansion()
