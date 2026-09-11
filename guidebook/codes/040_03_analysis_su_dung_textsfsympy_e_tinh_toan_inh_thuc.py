import sympy as sp


def verify_jacobian_decoupling():
    u_n, u_prev = sp.symbols('u_n u_prev')
    # Map F(X): [u_{n+1}, u_n]
    f_next = sp.sqrt(u_n * u_prev)

    # State transition vector
    F = sp.Matrix([f_next, u_n])
    X = sp.Matrix([u_n, u_prev])

    # Compute Jacobian Matrix
    J = F.jacobian(X)
    print("Symbolic Jacobian Matrix of the 2D system:")
    sp.pprint(J)


verify_jacobian_decoupling()
