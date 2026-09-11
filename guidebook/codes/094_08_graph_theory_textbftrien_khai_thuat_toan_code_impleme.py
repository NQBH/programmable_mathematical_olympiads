import sympy as sp


def verify_cayley_formula(n_val):
    # Construct the exact Laplacian Matrix for the complete graph K_n
    L = sp.Matrix(n_val, n_val, lambda i, j: (n_val - 1) if i == j else -1)

    # Delete terminal row and column to extract the Principal Minor
    L_minor = L[:-1, :-1]

    # Execute exact symbolic determinant evaluation
    spanning_trees = sp.factor(L_minor.det())

    print(
        f"Output: Spanning tree cardinality of K_{n_val} via Laplacian determinant: {spanning_trees}")
    print(
        f"Output: Verified against Cayley\'s Formula (n^(n-2)): {n_val**(n_val - 2)}")

    if spanning_trees == n_val**(n_val - 2):
        print("=> Formal Verification: Kirchhoff-Cayley structural isomorphism confirmed.")


verify_cayley_formula(5)
