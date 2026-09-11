import sympy as sp


def verify_gradient_vanishing():
    h_prev, W, x, U = sp.symbols('h_prev W x U')

    # Sigmoid mapping f(u)
    sigma = sp.tanh
    h_curr = sigma(W * h_prev + U * x)

    # Chain rule derivative dh_t / dh_{t-1}
    derivative = sp.diff(h_curr, h_prev)
    print("Local Recurrence Derivative (Jacobian):")
    sp.pprint(derivative)

    # As t -> infinity, product of derivatives leads to zero or infinity
    print("Note: Multiplying this term T times dictates stability vs chaos.")


verify_gradient_vanishing()
