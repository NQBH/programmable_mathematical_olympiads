from itertools import permutations


def solve_n_queens(n):
    total_solutions = 0
    for perm in permutations(range(n)):
        diag1 = len(set(r - c for r, c in enumerate(perm)))
        diag2 = len(set(r + c for r, c in enumerate(perm)))
        if diag1 == n and diag2 == n:
            total_solutions += 1
    return total_solutions


assert solve_n_queens(8) == 92
print("Phase 3 Verification: 8-Queens verified = 92 solutions.")
