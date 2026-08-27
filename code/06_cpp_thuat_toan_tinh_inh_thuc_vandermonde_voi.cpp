#include <iostream>
#include <vector>
using namespace std;

// Tinh dinh thuc Vandermonde dua tren tich cac hieu so kieu chieu (O(N^2))
long long vandermondeDeterminant(const vector<long long>& x, long long MOD) {
    int n = x.size();
    long long det = 1;
    // Duyet qua moi cap (i, j) voi i < j nhung bo qua cac phep bien doi cot
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diff = (x[j] - x[i]) % MOD;
            if (diff < 0) diff += MOD;
            det = (det * diff) % MOD;
        }
    }
    return det;
}


int main() {
    vector<long long> x = {1, 2, 3, 4};
    long long MOD = 1e9 + 7;
    cout << "Vandermonde Determinant (x={1,2,3,4}): " << vandermondeDeterminant(x, MOD) << endl;
    return 0;
}
