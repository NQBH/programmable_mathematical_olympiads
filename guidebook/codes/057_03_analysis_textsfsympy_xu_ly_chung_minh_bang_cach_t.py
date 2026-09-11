import sympy as sp


def verify_integral_mvt():
    x, c = sp.symbols('x c', real=True)
    a, b = 0, 1

    # Test functions
    f = x
    g = x**2

    I_f = sp.integrate(f, (x, a, b))
    I_g = sp.integrate(g, (x, a, b))

    # Equation to solve: g(c) * I_f = f(c) * I_g
    eq = sp.Eq(g.subs(x, c) * I_f, f.subs(x, c) * I_g)

    # Solve for c
    roots = sp.solve(eq, c)
    valid_roots = [r for r in roots if a < r < b]

    print(f"I_f = {I_f}, I_g = {I_g}")
    print(f"Roots in (a,b): {valid_roots}")


verify_integral_mvt()
