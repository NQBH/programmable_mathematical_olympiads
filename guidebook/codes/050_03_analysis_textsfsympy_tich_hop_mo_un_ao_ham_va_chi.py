import sympy as sp


def verify_isolated_derivative():
    x = sp.Symbol('x')
    n = 6
    k = 4  # Target index

    # Defining the full product polynomial
    roots = list(range(1, n + 1))
    f_x = sp.prod([x - r for r in roots])

    # Symbolic differentiation and exact substitution
    f_prime = sp.diff(f_x, x)
    val_at_k = f_prime.subs(x, k)

    # Analytic formula verification (-1)^(n-k) * (k-1)! * (n-k)!
    analytic_val = ((-1)**(n - k)) * sp.factorial(k - 1) * sp.factorial(n - k)

    assert val_at_k == analytic_val
    print(f"Analytic validation successful for f'({k}): {val_at_k}")


verify_isolated_derivative()
