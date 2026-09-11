#include <iostream>
#include <vector>
#include <cassert>

using Matrix = std::vector<std::vector<long long>>;

Matrix mat_mul(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<long long>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Matrix mat_pow(Matrix A, long long p) {
    int n = A.size();
    Matrix res(n, std::vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (p > 0) {
        if (p & 1) res = mat_mul(res, A);
        A = mat_mul(A, A);
        p >>= 1;
    }
    return res;
}

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

int main() {
    // Bai 11: Tinh A^n
    Matrix A = {
        {2, 0, 0},
        {0, 3, 0},
        {0, 1, 2}
    };

    std::cout << "Kiem chung Bai 11: Luy thua ma tran A^n\n";
    for (long long n = 1; n <= 10; ++n) {
        Matrix num_pow = mat_pow(A, n);
        
        long long p2 = power(2, n);
        long long p3 = power(3, n);
        Matrix closed_form = {
            {p2, 0, 0},
            {0, p3, 0},
            {0, p3 - p2, p2}
        };

        assert(num_pow == closed_form);
    }
    std::cout << "Cong thuc dong A^n = diag(2^n, 3^n, 2^n) + E_32*(3^n - 2^n) dung voi moi n.\n\n";

    // Bai 12: Ma tran hang 1 thoa A^2 = lambda * A
    std::cout << "Kiem chung Bai 12: Ma tran hang 1 A = u * v^T\n";
    std::vector<long long> u = {2, -1, 3};
    std::vector<long long> v = {1, 4, -2};
    int dim = 3;
    Matrix R(dim, std::vector<long long>(dim, 0));
    long long trace_R = 0;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            R[i][j] = u[i] * v[j];
        }
        trace_R += R[i][i];
    }

    Matrix R2 = mat_mul(R, R);
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            assert(R2[i][j] == trace_R * R[i][j]);
        }
    }
    std::cout << "Xac thuc hoan tat: R^2 == tr(R) * R voi tr(R) = " << trace_R << "\n";

    return 0;
}
