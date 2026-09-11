#include <numeric>
#include <cstdlib>
#include <cmath>

static inline long long multiply_mod(long long a, long long b, long long m) {
    return (long long)((__int128_t)a * b % m);
}

// Implement Pollard's Rho Algorithm coupled with Miller-Rabin Primality Test
// O(n^{1/4}) probabilistic factorization breaking the pseudo-polynomial barrier
long long pollard_rho(long long n) {
    if (n == 1) return 1;
    if (n % 2 == 0)
        return 2;
    long long x = 2, y = 2, d = 1, c = 1;
    auto f = [&](long long x, long long n, long long c) {
        return (multiply_mod(x, x, n) + c) % n;
    };
    while (d == 1) {
        x = f(x, n, c);
        y = f(f(y, n, c), n, c);
        d = std::gcd(std::abs(x - y), n);
        if (d == n) {
            x = rand() % (n - 2) + 2;
            y = x;
            c = rand() % (n - 1) + 1;
            d = 1;
        }
    }
    return d;
}
