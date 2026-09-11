import sympy as sp
from sympy.combinatorics import CyclicGroup


def verify_group_action(n, K):
    # Initialize Cyclic Group C_n
    G = CyclicGroup(n)

    # Compute Cycle Index Polynomial
    # Z(G) = (1/|G|) * sum(prod(x_len^count) for g in G)
    vars = [sp.Symbol(f'x_{i}') for i in range(1, n + 1)]
    poly = 0
    for g in G.elements:
        term = 1
        for length, count in g.cycle_structure.items():
            term *= vars[length - 1]**count
        poly += term
    Z = poly / len(G.elements)

    print(f"Output: Cycle Index Polynomial of rotation group C_{n}:")
    print(Z)

    # Evaluate orbits for K colors
    x_vars = {sp.Symbol(f'x_{i}'): K for i in range(1, n + 1)}
    total_orbits = Z.subs(x_vars)

    print(f"Output: Distinct equivalence classes (K={K}): {total_orbits}")
    assert total_orbits == 24


verify_group_action(4, 3)
