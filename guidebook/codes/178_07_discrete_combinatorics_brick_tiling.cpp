#include <iostream>
#include <vector>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: Brick / Domino Grid Tiling via Bitmask Dynamic Programming
 * Case 1: 3x5 grid - Odd area (15) => 0 tilings (Parity Obstruction).
 * Case 2: 4x5 grid - Even area (20) => exactly 95 valid domino tilings.
 * Case 3: 2xn grid - Matches Fibonacci F_{n+1} sequence.
 */

void generate_next_masks(int row, int m, int current_mask, int next_mask, std::vector<int>& next_states) {
    if (row == m) {
        next_states.push_back(next_mask);
        return;
    }
    if ((current_mask & (1 << row)) != 0) {
        generate_next_masks(row + 1, m, current_mask, next_mask, next_states);
    } else {
        // Place horizontal domino: (row, col) and (row, col + 1)
        generate_next_masks(row + 1, m, current_mask, next_mask | (1 << row), next_states);
        // Place vertical domino: (row, col) and (row + 1, col)
        if (row + 1 < m && (current_mask & (1 << (row + 1))) == 0) {
            generate_next_masks(row + 2, m, current_mask, next_mask, next_states);
        }
    }
}

long long count_domino_tilings(int m, int n) {
    if ((m * n) % 2 != 0) return 0;
    if (m > n) std::swap(m, n);

    std::vector<long long> dp(1 << m, 0);
    dp[0] = 1;

    for (int col = 0; col < n; ++col) {
        std::vector<long long> next_dp(1 << m, 0);
        for (int mask = 0; mask < (1 << m); ++mask) {
            if (dp[mask] == 0) continue;
            std::vector<int> next_states;
            generate_next_masks(0, m, mask, 0, next_states);
            for (int nxt : next_states) {
                next_dp[nxt] += dp[mask];
            }
        }
        dp = next_dp;
    }
    return dp[0];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "--- Grid Domino Tiling: Bitmask DP Verification ---\n";

    // 1. Verify 3x5 grid: impossible due to odd area
    long long tilings_3x5 = count_domino_tilings(3, 5);
    std::cout << "Domino tilings of 3x5 grid: " << tilings_3x5 << " (Expected: 0)\n";
    assert(tilings_3x5 == 0);

    // 2. Verify 4x5 grid: exactly 95 tilings
    long long tilings_4x5 = count_domino_tilings(4, 5);
    std::cout << "Domino tilings of 4x5 grid: " << tilings_4x5 << " (Expected: 95)\n";
    assert(tilings_4x5 == 95);

    // 3. Verify 2xn grid matching Fibonacci sequence
    std::vector<long long> expected_fib = {1, 2, 3, 5, 8, 13, 21, 34};
    for (int n = 1; n <= 8; ++n) {
        long long res = count_domino_tilings(2, n);
        assert(res == expected_fib[n - 1]);
    }
    std::cout << "Domino tilings of 2xn match Fibonacci sequence F_{n+1} for n in [1, 8].\n";

    std::cout << "Verification successful: All tiling counts match exact combinatorial invariants.\n";
    return 0;
}
