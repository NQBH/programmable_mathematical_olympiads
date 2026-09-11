#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAX_n = 21544347; // n^{2/3} precomputation boundary for n = 10^{11}
__int128_t phi_prefix[MAX_n];
unordered_map<long long, __int128_t> memo_Phi;

// O(n^{2/3}) partial sieve for base cases
void precomputeSieve() {
    // Standard Linear Sieve initialization omitted for brevity
    // Populates phi_prefix[x] = phi_prefix[x-1] + phi[x]
}

// O(n^{2/3}) Mertens Trick to compute Prefix Sum of Euler Totient
__int128_t Phi(long long x) {
    if (x < MAX_n)
        return phi_prefix[x];
    if (memo_Phi.count(x))
        return memo_Phi[x];

    __int128_t res = (__int128_t)x * (x + 1) / 2;
    for (long long l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        res -= (r - l + 1) * Phi(x / l);
    }
    return memo_Phi[x] = res;
}

// Integrate Block Division algorithm to evaluate final Dirichlet convolution
__int128_t calculateGCDSum(long long n) {
    __int128_t total_sum = 0;
    for (long long l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        long long count = n / l;
        total_sum += (Phi(r) - Phi(l - 1)) * (__int128_t)count * count;
    }
    return total_sum;
}
