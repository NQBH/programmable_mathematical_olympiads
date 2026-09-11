#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Solves generic dimension reduction parameterized by lambda
void compute_linear_subspaces(double lambda) {
    vector<vector<double>> M = {
        {1, lambda, -1, 2}, {2, -1, lambda, 5}, {1, 10, -6, 1}};

    int rank = 0;
    int m = 3, n = 4;
    vector<bool> pivot_col(n, false);

    // Gaussian Elimination for Rank Evaluation
    for (int col = 0, row = 0; col < n && row < m; ++col) {
        int sel = row;
        for (int i = row; i < m; ++i)
            if (abs(M[i][col]) > abs(M[sel][col]))
                sel = i;

        if (abs(M[sel][col]) < 1e-9)
            continue;

        swap(M[sel], M[row]);
        pivot_col[col] = true;

        for (int i = row + 1; i < m; ++i) {
            double factor = M[i][col] / M[row][col];
            for (int j = col; j < n; ++j)
                M[i][j] -= factor * M[row][j];
        }
        row++;
        rank = row;
    }

    cout << "Lambda: " << lambda << " -> Dim(Im f): " << rank << "\n";
    cout << "Dim(Ker f): " << n - rank << "\n";
}
