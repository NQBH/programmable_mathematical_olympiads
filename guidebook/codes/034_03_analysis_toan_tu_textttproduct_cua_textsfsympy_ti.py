import sympy as sp


def verify_telescoping_product():
    k, n = sp.symbols('k n', integer=True)
    # Let f(k) be a rational function: (k+1)/(k+2)
    f_k = (k + 1) / (k + 2)

    closed_form_prod = sp.Product(f_k, (k, 1, n - 1)).doit()
    print("Closed-form Product evaluation via Gamma/Factorial:")
    sp.pprint(sp.simplify(closed_form_prod))


verify_telescoping_product()
