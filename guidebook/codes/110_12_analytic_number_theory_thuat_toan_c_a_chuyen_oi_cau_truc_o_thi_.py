import sympy as sp
from sympy import totient


def verify_dirichlet_convolution(n):
    raw_2d_sum = sum(sp.gcd(i, j) for i in range(1, n + 1)
                     for j in range(1, n + 1))

    euler_reduced_sum = sum(totient(d) * (n // d) **
                            2 for d in range(1, n + 1))

    print(f"Output: Execution via raw 2D combinatorial boundary: {raw_2d_sum}")
    print(f"Output: Execution via 1D Euler totient reduced sequence: {euler_reduced_sum}")

    if raw_2d_sum == euler_reduced_sum:
        print("=> Formal Verification: 2D GCD sum reduction via Euler totient identity confirmed.")
    assert raw_2d_sum == euler_reduced_sum


verify_dirichlet_convolution(100)
