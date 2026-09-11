import sympy as sp


def verify_functional_variance():
    x, t = sp.symbols('x t', real=True)
    a, b = 0, 1

    f = sp.exp(x)  # Test function

    # Define functional F(t)
    F_t = sp.integrate((f - t)**2, (x, a, b))

    # Differentiate wrt t
    dF_dt = sp.diff(F_t, t)

    # Solve for optimal t
    t_opt = sp.solve(dF_dt, t)[0]

    # Calculate analytic mean
    f_mean = sp.integrate(f, (x, a, b)) / (b - a)

    assert sp.simplify(t_opt - f_mean) == 0
    print(f"Optimal t matches mean analytically: {t_opt}")


verify_functional_variance()
