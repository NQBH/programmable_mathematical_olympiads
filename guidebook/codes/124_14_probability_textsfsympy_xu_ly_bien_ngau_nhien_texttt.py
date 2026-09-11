import sympy as sp
from sympy import Eq
from sympy.stats import Die, P


def verify_dice_events():
    # Define two independent 6-sided dice
    D1, D2 = Die('D1', 6), Die('D2', 6)

    # Event: Sum equals 7
    prob_sum = P(Eq(D1 + D2, 7))
    print(f"P(D1 + D2 = 7) = {prob_sum}")

    # Event: Identical parity
    prob_parity = P(Eq(D1 % 2, D2 % 2))
    print(f"P(Same parity) = {prob_parity}")


verify_dice_events()
