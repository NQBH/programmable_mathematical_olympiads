import sys
sys.set_int_max_str_digits(100000)
import sympy as sp


def verify_nilpotent_derivative():
    X = sp.Symbol('X')

    # Generic polynomial term near the boundary
    # Term in Ker(g)
    p_ker = X**1739
    # Term in Im(g) when derived
    p_im = X**1740

    # Apply operator g = D^{1740}
    g_ker = sp.diff(p_ker, X, 1740)
    g_im = sp.diff(p_im, X, 1740)

    print(f"g(X^1739) = {g_ker} -> Exists within Kernel.")
    print(f"g(X^1740) = {g_im} -> Exists within Image.")


verify_nilpotent_derivative()
