#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
const int MOD = 998244353;
const int ROOT = 3; // Primitive root of 998244353

// Montgomery Reduction architecture to replace % operator
struct Montgomery {
    unsigned long long n, nr;
    Montgomery(unsigned long long n) : n(n) {
        nr = 1; for (int i = 0; i < 5; ++i) nr *= 2 - n * nr;
    }
    unsigned long long reduce(unsigned long long x) const {
        unsigned long long m = (((unsigned long long)((unsigned int)x * (unsigned int)-nr) * n) + x) >> 32;
        return m >= n ? m - n : m;
    }
    unsigned long long transform(unsigned long long x) const { return (x << 32) % n; }
} mont(998244353);

// Fast modular exponentiation
long long modpow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Hardware-optimized In-Place Iterative NTT (Number Theoretic Transform)
void apex_ntt(vector<int> &a, bool invert) {
    int n = a.size();
    assert((n & (n - 1)) == 0 && n > 0); // Requires exact power of 2 for bit-reversal

    // 1. Bit-Reversal Permutation (O(n) memory locality structuring)
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    // 2. Iterative Bottom-Up Merging with Modulo Arithmetic
    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = modpow(ROOT, (MOD - 1) / len);
        if (invert) wlen = modpow(wlen, MOD - 2); // Inverse primitive root

        unsigned long long w_mont = mont.transform(1);
        unsigned long long wlen_mont = mont.transform(wlen);
        for (int i = 0; i < n; i += len) {
            unsigned long long w = w_mont;
            for (int j = 0; j < len / 2; j++) {
                // Branchless Butterfly Operation with Montgomery Reduction (no % operator)
                unsigned long long u = a[i + j];
                unsigned long long v = mont.reduce((unsigned long long)a[i + j + len / 2] * w);
                a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                a[i + j + len / 2] = u >= v ? u - v : u + MOD - v; // Safe 2's complement pseudo-subtraction
                w = mont.reduce(w * wlen_mont);
            }
        }
    }

    // Normalization for Inverse NTT
    if (invert) {
        long long inv_n = modpow(n, MOD - 2);
        for (int &x : a) x = (x * inv_n) % MOD;
    }
}
