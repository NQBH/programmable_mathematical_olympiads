#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAX_n = 2000005; // Allocate dynamic memory bounds up to n = 10^6

long long fact[MAX_n], invFact[MAX_n];

// Binary modular exponentiation operator
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

// O(n) factorial precomputation establishing O(1) query bounds
void precomputeFactorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX_n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX_n - 1] = powerMod(fact[MAX_n - 1], MOD - 2);
    for (int i = MAX_n - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Extract structural Catalan coefficient C_n in strict O(1) time
long long getCatalan(int n) {
    if (n < 0 || 2 * n >= MAX_n)
        return 0;
    // C_n = (2n)! / ( n! * (n+1)! )
    long long num = fact[2 * n];
    long long den = (invFact[n] * invFact[n + 1]) % MOD;
    return (num * den) % MOD;
}
