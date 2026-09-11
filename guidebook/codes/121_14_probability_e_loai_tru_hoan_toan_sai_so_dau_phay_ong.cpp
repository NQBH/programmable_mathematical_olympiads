#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
typedef unsigned long long ull;

// O(n^2) Pascal's Triangle for combination bounds to prevent overflow
ull compute_combinations(int n, int k) {
    if (k > n || k < 0)
        return 0;
    if (k == 0 || k == n)
        return 1;
    vector<ull> C(k + 1, 0);
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            C[j] = C[j] + C[j - 1];
        }
    }
    return C[k];
}

void evaluate_coin_toss_probability(int n, int k) {
    ull favorable_outcomes = compute_combinations(n, k);
    ull total_space = 1ULL << n;

    ull divisor = std::gcd(favorable_outcomes, total_space);

    cout << "Exact P(X=" << k << ") = " << (favorable_outcomes / divisor) << "/"
         << (total_space / divisor) << endl;
}
