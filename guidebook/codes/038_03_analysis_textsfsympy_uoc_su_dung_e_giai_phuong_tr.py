import sympy as sp


def verify_linearization():
    x = sp.Symbol('x')
    # Non-linear logistic map f(x) = 2*x*(1-x)
    f_x = 2 * x * (1 - x)

    # Extract fixed points analytically
    fixed_points = sp.solve(f_x - x, x)

    for fp in fixed_points:
        derivative = sp.diff(f_x, x).subs(x, fp)
        print(f"Fixed Point: {fp}, Multiplier (Eigenvalue): {derivative}")
        if abs(derivative) not in [0, 1]:
            print(" -> Topologically conjugate to a linear map locally.")


verify_linearization()
