#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 2000005; // Ho tro truy van N le toi 1 trieu

long long fact[MAXN], invFact[MAXN];

// Toan tu luy thua nhi phan tinh Nghich dao Module
long long powerMod(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Tien xu ly Giai thua O(N) nham dat truy van O(1)
void precomputeFactorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = powerMod(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Thuat toan trich xuat cau hinh Catalan C_n trong O(1) chu ky may
long long getCatalan(int n) {
    if (n < 0) return 0;
    // C_n = (2n)! / ( n! * (n+1)! )
    long long num = fact[2 * n];
    long long den = (invFact[n] * invFact[n + 1]) % MOD;
    return (num * den) % MOD;
}


int main() {
    precomputeFactorials();
    for(int i = 0; i <= 5; i++) {
        cout << "Catalan C_" << i << " = " << getCatalan(i) << endl;
    }
    return 0;
}
