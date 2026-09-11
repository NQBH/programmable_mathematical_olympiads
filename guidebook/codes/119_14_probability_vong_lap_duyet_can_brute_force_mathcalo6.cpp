#include <iostream>
#include <vector>

using namespace std;
typedef double prob_t;

// O(n * a * 6) DP Convolution for n-dice sum distribution
prob_t compute_n_dice_sum(int n, int a) {
    if (a < n || a > 6 * n)
        return 0.0;

    // dp[i][j] stores the probability of reaching sum j using i dice
    vector<vector<prob_t>> dp(n + 1, vector<prob_t>(a + 1, 0.0));
    dp[0][0] = 1.0;

    prob_t face_prob = 1.0 / 6.0;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= a; ++j) {
            for (int f = 1; f <= 6; ++f) {
                if (j - f >= 0) {
                    dp[i][j] += dp[i - 1][j - f] * face_prob;
                }
            }
        }
    }

    return dp[n][a];
}
