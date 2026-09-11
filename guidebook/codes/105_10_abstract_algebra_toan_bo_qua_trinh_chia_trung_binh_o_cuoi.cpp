#include <iostream>
#include <numeric>
using namespace std;

const long long MOD = 1e9 + 7;

// Binary exponentiation on the finite field F_p
long long powerMod(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Compute Euler Totient Function phi(x) in O(sqrt(x))
long long eulerTotient(long long x) {
    long long res = x;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0)
                x /= i;
            res -= res / i;
        }
    }
    if (x > 1)
        res -= res / x;
    return res;
}

// Implement Burnside's Lemma over divisor lattice to collapse O(n) to
// O(sqrt(n))
long long burnsideNecklace(long long n, long long K) {
    long long total_fixed_points = 0;

    // Iterate strictly across the divisor lattice of n
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            // Evaluates fixed points weighted by the Euler Totient Function
            // phi(n/d)
            total_fixed_points =
                (total_fixed_points +
                 1LL * eulerTotient(n / d) % MOD * powerMod(K, d)) %
                MOD;

            if (d * d != n) {
                long long d2 = n / d;
                total_fixed_points =
                    (total_fixed_points +
                     1LL * eulerTotient(n / d2) % MOD * powerMod(K, d2)) %
                    MOD;
            }
        }
    }

    // Finalize Burnside orbit averaging via modular inverse |G|^{-1}
    if (n % MOD == 0) {
        cerr << "Error: n is divisible by MOD; modular inverse does not exist in F_p." << endl;
        return -1;
    }
    long long mod_inverse_n = powerMod(n, MOD - 2);
    return (total_fixed_points * mod_inverse_n) % MOD;
}
