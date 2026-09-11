import sympy as sp


def verify_vandermonde(n):
    # Initialize the abstract symbolic variable field
    x = sp.symbols(f'x1:{n + 1}')

    # Construct the symbolic Vandermonde matrix V_n
    V = sp.Matrix(n, n, lambda i, j: x[i]**j)

    # Execute determinant computation and structural algebraic factorization
    det_V = sp.factor(V.det())

    print(f"Output: Symbolic Vandermonde determinant (n={n}):")
    print(det_V)


# Instantiate abstract polynomial ring for empirical validation (n = 4)
verify_vandermonde(4)
# Output: (x1 - x2)*(x1 - x3)*(x1 - x4)*(x2 - x3)*(x2 - x4)*(x3 - x4)
