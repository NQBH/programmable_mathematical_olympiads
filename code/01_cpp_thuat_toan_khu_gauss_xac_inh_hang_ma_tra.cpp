#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Xac dinh hang (rank) cua ma tran M(a)
int matrixRank(vector<vector<double>> M) {
    int n = M.size();
    int rank = 0;
    for (int i = 0; i < n; i++) {
        // Pivot selection nham giam thieu sai so dau phay dong
        if (abs(M[i][i]) < 1e-9) {
            bool swapped = false;
            for (int j = i + 1; j < n; j++) {
                if (abs(M[j][i]) > 1e-9) {
                    swap(M[i], M[j]);
                    swapped = true;
                    break;
                }
            }
            if (!swapped) continue;
        }
        rank++;
        // Thuc hien phep khu Gauss tren cac hang phia duoi
        for (int j = i + 1; j < n; j++) {
            double factor = M[j][i] / M[i][i];
            for (int k = i; k < n; k++) {
                M[j][k] -= factor * M[i][k];
            }
        }
    }
    return rank;
}


int main() {
    vector<vector<double>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Rank of matrix: " << matrixRank(matrix) << endl;
    return 0;
}
