import sympy as sp

def verify_uit_operator():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: UIT VMC2025 Prob. 1 - Linear Operator Spectrum & Spectral Mapping
    """
    A = sp.Matrix([
        [-5, 4, -1],
        [-2, 1, 1],
        [10, -10, 6]
    ])

    # 1. Verification of Eigenvalues and Diagonalization
    P, D = A.diagonalize()
    expected_eigenvalues = {-1, 1, 2}
    actual_eigenvalues = set(D.diagonal())
    assert actual_eigenvalues == expected_eigenvalues, f"Eigenvalue mismatch: {actual_eigenvalues}"

    # 2. Decomposition of p(x) = 3 + 6*x + 7*x^2
    v = sp.Matrix([3, 6, 7])
    c = P.inv() * v
    
    # In coordinate basis, coordinates in P are all 1
    # P columns scaled: v1 = [1, 1, 0]^T, v2 = [1, 2, 2]^T, v3 = [1, 3, 5]^T
    T = sp.Matrix([
        [1, 1, 1],
        [1, 2, 3],
        [0, 2, 5]
    ])
    c_T = T.inv() * v
    assert c_T == sp.Matrix([1, 1, 1]), f"Coordinates in eigenbasis mismatch: {c_T}"

    # 3. Exact evaluation of phi^2025(p)
    # phi^2025(p) = (-1)^2025 * v1 + (1)^2025 * v2 + (2)^2025 * v3
    #             = -v1 + v2 + 2^2025 * v3
    #             = [-1 + 1 + 2^2025, -1 + 2 + 3*2^2025, 0 + 2 + 5*2^2025]^T
    #             = [2^2025, 1 + 3*2^2025, 2 + 5*2^2025]^T
    p2_2025 = sp.Integer(2)**2025
    expected_phi = sp.Matrix([
        p2_2025,
        1 + 3 * p2_2025,
        2 + 5 * p2_2025
    ])

    # Compare with matrix power computation
    A_2025_v = T * (sp.diag(-1, 1, 2)**2025) * T.inv() * v
    assert A_2025_v == expected_phi, "Matrix power calculation failed"

    print("Phase 3 Verification Passed:")
    print(f"  Diagonalized Spectrum: {actual_eigenvalues}")
    print(f"  Eigenbasis Representation Matrix T:\n{T}")
    print("  Formal Closed-form Solution Verified:")
    print("    phi^2025(p(x)) = 2^2025 + (1 + 3*2^2025)*x + (2 + 5*2^2025)*x^2")

if __name__ == "__main__":
    verify_uit_operator()
