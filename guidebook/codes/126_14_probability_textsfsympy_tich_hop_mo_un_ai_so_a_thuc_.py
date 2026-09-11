import sympy as sp


def verify_dice_generating_function():
    x = sp.Symbol('x')
    n = 10
    target_sum = 35

    # Polynomial representing a single 6-sided die
    single_die = sum(x**i for i in range(1, 7))

    # Generating function for n dice
    G_x = sp.expand(single_die**n)

    # Extracting combinatorial coefficient
    exact_ways = G_x.coeff(x, target_sum)

    total_space = 6**n
    prob = sp.Rational(exact_ways, total_space)
    print(f"P(Sum={target_sum} | n={n}) = {prob}")


verify_dice_generating_function()
