import sympy as sp


def verify_cs_integral_bound():
    x = sp.Symbol('x', real=True)
    a, b = 1, 2

    f = x  # Simple linear test function

    I_f = sp.integrate(f, (x, a, b))
    I_inv_f = sp.integrate(1 / f, (x, a, b))

    product = I_f * I_inv_f
    cs_bound = (b - a)**2

    print(f"I_f * I_inv_f = {product}")
    print(f"Cauchy-Schwarz Lower Bound: {cs_bound}")
    print(f"Condition: {product} >= {cs_bound} is {product >= cs_bound}")


verify_cs_integral_bound()
