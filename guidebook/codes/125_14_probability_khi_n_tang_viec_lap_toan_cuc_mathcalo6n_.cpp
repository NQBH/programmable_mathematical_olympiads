#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

// O(n * a) Dynamic Programming formulation mapping generating functions
void evaluate_n_dice_sum(int n, int a) {
    if (a < n || a > 6 * n) {
        cout << "Impossible target sum." << endl;
        return;
    }

    // dp[i][j] stores number of configurations of i dice summing to j
    vector<vector<ull>> dp(n + 1, vector<ull>(a + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= a; ++j) {
            for (int k = 1; k <= 6; ++k) {
                if (j >= k)
                    dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    cout << "Exact configurations for sum=" << a << " with " << n
         << " dice: " << dp[n][a] << endl;
}
