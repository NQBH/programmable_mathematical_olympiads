import sympy as sp


def verify_matrix_exponential():
    A = sp.Matrix([
        [1, -1],
        [0, 2]
    ])

    # SymPy computes e^A exactly using spectral or Jordan decomposition
    exp_A = sp.exp(A)
    print("Exact symbolic exponential matrix:")
    sp.pprint(exp_A)


verify_matrix_exponential()
