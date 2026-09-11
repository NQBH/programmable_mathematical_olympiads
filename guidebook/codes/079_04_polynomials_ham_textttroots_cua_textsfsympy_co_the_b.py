import sympy as sp


def verify_newton_sums():
    x = sp.Symbol('x')
    P_x = x**4 - 2 * x**3 - 1

    # Finding analytic roots (Quartic formula)
    rts = sp.roots(P_x, x)

    # Compute sum of cubes over exact radical expressions
    sum_cubes = sum([r**3 for r in rts])

    print("Exact symbolic evaluation of S_3:")
    sp.pprint(sp.simplify(sum_cubes))


verify_newton_sums()
