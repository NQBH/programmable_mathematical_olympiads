#include <iostream>
#include <vector>

using namespace std;
typedef double prob_t;

// O(n*k) Dynamic Programming for absorbing Markov Chain probability
prob_t compute_consecutive_heads(int n, int k) {
    // dp[i] stores the probability of currently having exactly i consecutive
    // heads dp[k] is the absorbing state probability
    vector<prob_t> dp(k + 1, 0.0);
    dp[0] = 1.0;

    for (int step = 0; step < n; ++step) {
        vector<prob_t> next_dp(k + 1, 0.0);
        // From any non-absorbing state, a tail resets the run to 0
        prob_t tail_prob = 0;
        for (int i = 0; i < k; ++i) {
            tail_prob += dp[i] * 0.5;
            next_dp[i + 1] += dp[i] * 0.5;
        }
        next_dp[0] = tail_prob;

        // The absorbing state transitions to itself deterministically (1.0)
        next_dp[k] += dp[k];

        dp = next_dp;
    }
    return dp[k];
}
