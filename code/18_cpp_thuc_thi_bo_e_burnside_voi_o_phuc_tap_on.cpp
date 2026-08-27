#include <iostream>
#include <numeric>
using namespace std;

const long long MOD = 1e9 + 7;

// Luy thua nhi phan tren truong F_p
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

// Thuat toan Burnside dem lop tuong duong (Equivalence Classes)
long long burnsideNecklace(int N, int K) {
    long long total_fixed_points = 0;
    
    // Duyet qua toan bo phan tu cua Nhom Quay C_N
    for (int i = 0; i < N; i++) {
        // So chu trinh roi rac (disjoint cycles) cua phep quay i
        int cycles = gcd(i, N); 
        
        // So diem bat dong |X^g| = K^{cycles}
        total_fixed_points = (total_fixed_points + powerMod(K, cycles)) % MOD;
    }
    
    // Nhan voi |G|^{-1} mod P de hoan tat trung binh cong Burnside
    long long mod_inverse_N = powerMod(N, MOD - 2);
    return (total_fixed_points * mod_inverse_N) % MOD;
}


long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int N = 4, K = 3;
    cout << "Burnside Equivalence Classes (N=" << N << ", K=" << K << "): " 
         << burnsideNecklace(N, K) << endl;
    return 0;
}
