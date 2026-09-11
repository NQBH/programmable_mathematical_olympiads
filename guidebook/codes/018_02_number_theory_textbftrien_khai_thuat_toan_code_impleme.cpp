#include <iostream>
#include <vector>

using namespace std;

// O(n log log n) Sieve for subset cardinality
int compute_prime_cardinality(int n) {
    if (n <= 1) return 0;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    int p_count = 0;

    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (is_prime[p])
            p_count++;
    }
    return p_count;
}
