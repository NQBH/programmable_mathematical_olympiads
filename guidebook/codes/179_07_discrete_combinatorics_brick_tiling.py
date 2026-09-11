import sympy as sp
import numpy as np

def verify_kasteleyn_tiling():
    """
    PMO Phase 3: Automated Symbolic Verification
    Problem: Domino / Brick Grid Tiling via Kasteleyn Closed-Form Formula
    """
    # 1. Kasteleyn closed-form formula for m x n grid:
    # N(m, n) = Prod_{j=1}^m Prod_{k=1}^n |4*cos^2(j*pi/(m+1)) + 4*cos^2(k*pi/(n+1))|^(1/4)
    def kasteleyn_count(m, n):
        if (m * n) % 2 != 0:
            return 0
        val = 1.0
        for j in range(1, m + 1):
            for k in range(1, n + 1):
                term = 4.0 * (np.cos(j * np.pi / (m + 1))**2) + 4.0 * (np.cos(k * np.pi / (n + 1))**2)
                val *= term**0.25
        return int(round(val))

    # 2. Assertions
    # 3x5 grid: odd area 15 => exactly 0 tilings
    assert kasteleyn_count(3, 5) == 0

    # 4x5 grid: even area 20 => exactly 95 tilings
    count_4x5 = kasteleyn_count(4, 5)
    assert count_4x5 == 95, f"Kasteleyn count mismatch for 4x5: {count_4x5} != 95"

    # 2xn grid: Fibonacci sequence F_{n+1}
    fib_expected = [1, 2, 3, 5, 8, 13, 21, 34]
    for n in range(1, 9):
        assert kasteleyn_count(2, n) == fib_expected[n - 1]

    print("Phase 3 Verification Passed:")
    print("  Parity Invariant: N(3, 5) = 0 (odd area obstruction).")
    print(f"  Kasteleyn Analytical Product: N(4, 5) = {count_4x5} (exact 95 tilings).")
    print("  Fibonacci Asymptotics: N(2, n) == F_{n+1} rigorously confirmed for all n in [1, 8].")

if __name__ == "__main__":
    verify_kasteleyn_tiling()
