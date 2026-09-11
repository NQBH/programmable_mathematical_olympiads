import sympy as sp


def verify_transfer_matrix():
    n = 3
    # Build transition matrix for independent set transitions
    # 1 if transition from state i to state j is valid, 0 otherwise
    # Constructing a generic example matrix for n=3
    T = sp.Matrix([
        [1, 0, 1],
        [0, 1, 0],
        [1, 0, 1]
    ])

    m = 5
    # T^{m-1} yields the valid paths across m rows
    Paths_Matrix = T**(m - 1)

    # Summing all matrix elements provides total valid configurations
    total_configurations = sum(Paths_Matrix)
    print(f"Total configurations for m={m}: {total_configurations}")


verify_transfer_matrix()
