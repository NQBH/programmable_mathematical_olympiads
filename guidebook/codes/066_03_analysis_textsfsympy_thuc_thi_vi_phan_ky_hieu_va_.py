import sympy as sp


def verify_arctan_leibniz():
    x = sp.Symbol('x')
    f = sp.atan(x)
    n = 5  # Verification depth

    # Calculate symbolic derivatives
    f_n = sp.diff(f, x, n)
    f_n_minus_1 = sp.diff(f, x, n - 1)
    f_n_minus_2 = sp.diff(f, x, n - 2)

    # Construct invariant equation
    eq = (1 + x**2) * f_n + 2 * (n - 1) * x * \
        f_n_minus_1 + (n - 2) * (n - 1) * f_n_minus_2

    assert sp.simplify(eq) == 0
    print(f"Invariant Equation strictly evaluates to 0 for n={n}")


verify_arctan_leibniz()
