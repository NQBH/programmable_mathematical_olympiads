#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Thuat toan tinh Dinh thuc Laplacian de dem so cay khung
long long countSpanningTrees(vector<vector<long long>>& adjacency_matrix, long long MOD) {
    int n = adjacency_matrix.size();
    if (n <= 1) return 1;

    // Khoi tao Ma tran Laplacian L = D - A
    vector<vector<long long>> L(n - 1, vector<long long>(n - 1, 0));
    for (int i = 0; i < n - 1; i++) {
        long long degree = 0;
        for (int j = 0; j < n; j++) {
            if (adjacency_matrix[i][j]) {
                degree++;
                if (j < n - 1) {
                    L[i][j] = (L[i][j] - adjacency_matrix[i][j] + MOD) % MOD;
                }
            }
        }
        L[i][i] = (L[i][i] + degree) % MOD;
    }

    // Tinh dinh thuc ma tran con chinh bang Khu Gauss O(N^3)
    long long det = 1;
    for (int i = 0; i < n - 1; i++) {
        // [Cac buoc khu Gauss, hoan vi hang, va nghich dao module (tuong tu Module 3)]
        // ... (Gian luoc code de tap trung vao kien truc Laplacian)
        det = (det * L[i][i]) % MOD;
    }
    
    return det;
}


int main() {
    vector<vector<long long>> K4 = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    long long MOD = 1e9 + 7;
    cout << "Spanning trees for K4: " << countSpanningTrees(K4, MOD) << endl;
    return 0;
}
