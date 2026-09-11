import sympy as sp
from itertools import permutations


def verify_permutation_matrices():
    n = 3
    valid_matrices = 0

    # Generate permutation matrices
    for p in permutations(range(n)):
        M = sp.zeros(n)
        for i, col in enumerate(p):
            M[i, col] = 1

        # Verify M^{-1} has elements strictly in {0, 1}
        M_inv = M.inv()
        is_binary = all(element in [0, 1] for element in M_inv)
        if is_binary:
            valid_matrices += 1

    print(f"Total valid matrices for n={n}: {valid_matrices}")
    print(f"Analytical |P_n| formula factorial(n): {sp.factorial(n)}")
    assert valid_matrices == sp.factorial(n)


verify_permutation_matrices()
