import sympy as sp


def verify_complex_trig_sum():
    x = sp.Symbol('x', real=True)
    n, k = sp.symbols('n k', integer=True, positive=True)

    # Defining a generic cosine series with constant coefficients (a_k = 1)
    # Mapping to exponential space C(x) + i S(x)
    Z_k = sp.exp(sp.I * k * x)

    # Evaluating sum from k=0 to n
    Z_sum = sp.Sum(Z_k, (k, 0, n)).doit()

    # Extracting exact algebraic real part (Cosine sum)
    cosine_sum = sp.re(Z_sum).simplify()
    print("Exact closed-form expression for the Cosine Series:")
    sp.pprint(cosine_sum)


verify_complex_trig_sum()
