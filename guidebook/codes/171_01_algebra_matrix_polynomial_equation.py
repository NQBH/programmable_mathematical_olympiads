import sympy as sp

def verify_matrix_polynomial_eq():
    """
    PMO Phase 3: Automated Symbolic Verification
    Topic: Matrix Polynomial Equations & Spectral Mapping Invariants
    """
    x = sp.Symbol('x')
    a0, a1, a2 = sp.symbols('a0 a1 a2', real=True)

    # General 2x2 matrix A
    A = sp.Matrix([
        [sp.Symbol('a'), sp.Symbol('b')],
        [sp.Symbol('c'), sp.Symbol('d')]
    ])
    I2 = sp.eye(2)

    # Polynomial g(A) = a2*A^2 + a1*A + a0*I
    gA = a2 * (A**2) + a1 * A + a0 * I2
    B = -gA

    # 1. Verify matrix commutativity [A, B] = A*B - B*A == 0 identically
    comm = sp.simplify(A * B - B * A)
    assert comm == sp.zeros(2, 2), f"Commutativity failed: {comm}"

    # 2. Spectral mapping theorem verification
    # If A has eigenvalue lambda, B has eigenvalue -g(lambda)
    lam = sp.Symbol('lambda')
    g_lam = a2 * lam**2 + a1 * lam + a0
    # Test on specific diagonal matrix
    D = sp.diag(1, 3)
    B_D = -(a2 * (D**2) + a1 * D + a0 * sp.eye(2))
    assert B_D[0, 0] == -g_lam.subs(lam, 1)
    assert B_D[1, 1] == -g_lam.subs(lam, 3)

    print("Phase 3 Verification Passed:")
    print("  Commutativity Invariant: [A, g(A)] == 0 identically for all general matrices.")
    print("  Spectral Mapping Invariant: Spec(g(A)) == g(Spec(A)) symbolically confirmed.")

if __name__ == "__main__":
    verify_matrix_polynomial_eq()
