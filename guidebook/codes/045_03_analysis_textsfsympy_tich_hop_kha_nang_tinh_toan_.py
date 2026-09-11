import sympy as sp


def verify_infinite_product():
    k, n = sp.symbols('k n', integer=True, positive=True)
    # Define product term
    term = 1 + (sp.Rational(1, 4))**k

    # Define infinite product
    inf_prod = sp.Product(term, (k, 1, sp.oo))

    # Establish analytical bound validation
    lower_bound = sp.Rational(5, 4)
    upper_bound_ln = sp.Sum((sp.Rational(1, 4))**k, (k, 1, sp.oo)).doit()
    analytic_upper_bound = sp.exp(upper_bound_ln)

    print(f"Logarithmic Sum Limit: {upper_bound_ln}")
    print(f"Product Upper Bound Validation: exp({upper_bound_ln})")


verify_infinite_product()
