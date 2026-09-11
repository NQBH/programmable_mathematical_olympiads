import sympy as sp


def verify_telescoping_sum():
    k, n = sp.symbols('k n', integer=True)
    # Let f(k) be a 3rd degree polynomial: k^3
    f_k = k**3

    closed_form_sum = sp.Sum(f_k, (k, 1, n - 1)).doit()
    print("Closed-form Faulhaber evaluation:")
    sp.pprint(sp.factor(closed_form_sum))


verify_telescoping_sum()
