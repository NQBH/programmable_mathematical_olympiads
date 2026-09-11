import sympy as sp


def verify_multiple_antiderivative():
    x, t = sp.symbols('x t')
    m = 3
    # Arbitrary continuous polynomial P(x)
    P_x = 5 * x**2 - 2 * x + 7

    # Method 1: Discrete iterative symbolic integration
    I_P = P_x
    for _ in range(m):
        I_P = sp.integrate(I_P, x)

    # Method 2: Continuous Cauchy repeated integration formula
    # Setting lower bound a = 0
    Cauchy_I = sp.integrate(
        (x - t)**(m - 1) * P_x.subs(x, t), (t, 0, x)) / sp.factorial(m - 1)

    print(f"Iterative discrete integral: {sp.expand(I_P)}")
    print(f"Cauchy continuous integral: {sp.expand(Cauchy_I)}")
    print(f"Equivalence verified: {sp.simplify(I_P - Cauchy_I) == 0}")


verify_multiple_antiderivative()
