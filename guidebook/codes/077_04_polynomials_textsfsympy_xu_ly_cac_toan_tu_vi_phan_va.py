import sympy as sp


def verify_extended_operators():
    x = sp.Symbol('x')
    n, k = 5, 3

    # Generic base polynomial of degree n
    P = sum(sp.Symbol(f'c_{i}') * x**i for i in range(n + 1))

    # Apply k-th order integral (assuming 0 constants for linearity mapping)
    I_P = P
    for _ in range(k):
        I_P = sp.integrate(I_P, x)

    print(f"Original Degree: {sp.degree(P, x)}")
    print(f"Mapped Integral Degree: {sp.degree(I_P, x)}")
    print(f"Lowest degree term in mapping: {x**k}")


verify_extended_operators()
