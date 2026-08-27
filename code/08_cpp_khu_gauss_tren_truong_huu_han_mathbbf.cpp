#include <iostream>
#include <vector>
using namespace std;

// Tinh luy thua nhi phan tren module p de tim Nghich dao Module
long long powerMod(long long base, long long exp, long long p) {
    long long res = 1;
    base %= p;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % p;
        base = (base * base) % p;
        exp /= 2;
    }
    return res;
}

// Tinh Modulo Inverse dua tren Dinh ly nho Fermat
long long modInverse(long long n, long long p) {
    return powerMod(n, p - 2, p);
}

// Thuat toan tinh Dinh thuc tren truong F_p voi do phuc tap O(N^3)
long long determinantModP(vector<vector<long long>> M, long long p) {
    int n = M.size();
    long long det = 1;
    for (int i = 0; i < n; i++) {
        if (M[i][i] == 0) {
            bool swapped = false;
            for (int j = i + 1; j < n; j++) {
                if (M[j][i] != 0) {
                    swap(M[i], M[j]);
                    det = (p - det) % p; // Doi dau dinh thuc
                    swapped = true;
                    break;
                }
            }
            if (!swapped) return 0;
        }
        det = (det * M[i][i]) % p;
        long long inv = modInverse(M[i][i], p);
        for (int j = i + 1; j < n; j++) {
            long long factor = (M[j][i] * inv) % p;
            for (int k = i; k < n; k++) {
                M[j][k] = (M[j][k] - factor * M[i][k]) % p;
                if (M[j][k] < 0) M[j][k] += p;
            }
        }
    }
    return det;
}


int main() {
    vector<vector<long long>> M = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 10}
    };
    long long p = 13;
    cout << "Determinant of M modulo " << p << " is: " << determinantModP(M, p) << endl;
    return 0;
}
