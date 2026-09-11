#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;
const int BLOCK_SIZE = 64; // L1 Cache line alignment

// Cache-friendly Matrix Multiplication via Loop Tiling
vector<vector<long long>> apex_matrix_mult(const vector<vector<long long>> &A,
                                           const vector<vector<long long>> &B) {
    int n = A.size();
    vector<vector<long long>> C(n, vector<long long>(n, 0));
    // Transpose B to achieve contiguous memory access (Spatial Locality)
    vector<vector<long long>> B_T(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            B_T[i][j] = B[j][i];

    // Block-level multiplication (Tiling)
    for (int i = 0; i < n; i += BLOCK_SIZE) {
        for (int j = 0; j < n; j += BLOCK_SIZE) {
            for (int k = 0; k < n; k += BLOCK_SIZE) {
                // Micro-kernel execution
                for (int ii = i; ii < min(i + BLOCK_SIZE, n); ++ii) {
                    for (int jj = j; jj < min(j + BLOCK_SIZE, n); ++jj) {
                        unsigned __int128 sum = 0;
                        // Sequential memory access for both A and B_T (Scalar 128-bit accumulator avoids overflow; for AVX2 SIMD, use 64-bit accumulator with smaller tile)
                        for (int kk = k; kk < min(k + BLOCK_SIZE, n); ++kk) {
                            sum += (unsigned __int128)A[ii][kk] * B_T[jj][kk];
                        }
                        C[ii][jj] = (C[ii][jj] + (long long)(sum % MOD)) % MOD;
                    }
                }
            }
        }
    }
    return C;
}
