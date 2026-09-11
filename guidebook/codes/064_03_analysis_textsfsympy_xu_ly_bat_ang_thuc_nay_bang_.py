import sympy as sp


def verify_trig_derivative_bound():
    x = sp.Symbol('x', real=True)
    a1, a2, a3 = sp.symbols('a1 a2 a3', real=True)

    f_x = a1 * sp.sin(x) + a2 * sp.sin(2 * x) + a3 * sp.sin(3 * x)

    # Calculate limit of f(x)/x as x -> 0
    lim_fx = sp.limit(f_x / x, x, 0)

    # Calculate analytic derivative at 0
    f_prime_0 = sp.diff(f_x, x).subs(x, 0)

    assert lim_fx == f_prime_0
    print(f"L'Hopital Limit matches Analytic Derivative: {lim_fx}")


verify_trig_derivative_bound()
