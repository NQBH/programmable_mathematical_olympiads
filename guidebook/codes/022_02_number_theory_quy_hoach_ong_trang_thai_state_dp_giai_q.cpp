#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// O(m * n^2) DP for exactly 1 brick per row in an alternating grid
ll compute_independent_paths(int m, int n) {
    if (m == 0 || n == 0) return 0;
    // dp[i][j] stores the number of valid configurations up to row i ending at
    // column j
    vector<vector<ll>> dp(m, vector<ll>(n, 0));

    for (int j = 0; j < n; ++j)
        dp[0][j] = 1;

    for (int i = 1; i < m; ++i) {
        for (int curr = 0; curr < n; ++curr) {
            for (int prev = 0; prev < n; ++prev) {
                // Adjacency constraint for alternating bricks
                // Depends on row parity. Simplified conceptual bounds:
                if (abs(curr - prev) >
                    1) { // Assuming abstract non-overlap limit
                    dp[i][curr] += dp[i - 1][prev];
                }
            }
        }
    }

    ll total_ways = 0;
    for (int j = 0; j < n; ++j)
        total_ways += dp[m - 1][j];
    return total_ways;
}
