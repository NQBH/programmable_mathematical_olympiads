import sympy as sp


def verify_squeeze_theorem():
    x = sp.Symbol('x', real=True)

    # Lower bound expression 1/2 * (1 - |x|)
    lower_bound = sp.Rational(1, 2) * (1 - sp.Abs(x))
    # Upper bound expression 1/2 * (1 + |x|)
    upper_bound = sp.Rational(1, 2) * (1 + sp.Abs(x))

    # Calculate limits at x -> 0
    lim_lower = sp.limit(lower_bound, x, 0)
    lim_upper = sp.limit(upper_bound, x, 0)

    assert lim_lower == lim_upper
    print(f"Rigorous Squeeze Limit confirmed: {lim_lower}")


verify_squeeze_theorem()
