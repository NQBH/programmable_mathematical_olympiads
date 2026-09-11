import sympy as sp


def verify_general_recurrence():
    n = sp.Symbol('n', integer=True)
    u = sp.Function('u')

    # Generic second-order linear recurrence: u(n) = a*u(n-1) + b*u(n-2)
    # Using Fibonacci as a specific evaluable topology
    recurrence = u(n) - u(n - 1) - u(n - 2)

    closed_form = sp.rsolve(recurrence, u(n), {u(0): 0, u(1): 1})
    print("Closed-form algebraic limit:")
    sp.pprint(sp.simplify(closed_form))


verify_general_recurrence()
