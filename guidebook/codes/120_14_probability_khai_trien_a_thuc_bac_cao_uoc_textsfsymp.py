import sympy as sp


def verify_n_dice_generating_function():
    x = sp.Symbol('x')
    n, a = 10, 35

    # Polynomial representing one die
    P_x = sum(x**i for i in range(1, 7)) / 6

    # Generating function for n dice
    F_x = sp.expand(P_x**n)

    # Extract specific coefficient for sum = a
    prob_sum_a = F_x.coeff(x, a)
    print(f"Exact algebraic probability for Sum={a} with {n} dice:")
    print(prob_sum_a)


verify_n_dice_generating_function()
