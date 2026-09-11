#include <iostream>
#include <vector>

using namespace std;

// O(d^2) Horner's Method for Polynomial Taylor Shift (x-a)
vector<double> polynomial_taylor_shift(vector<double> P, double a) {
    int d = P.size() - 1;
    vector<double> T_coeff(d + 1, 0.0);

    // Iterative synthetic division bypassing calculus
    for (int i = 0; i <= d; ++i) {
        T_coeff[i] = P[d];
        for (int j = d - 1; j >= i; --j) {
            P[j] += P[j + 1] * a;
        }
        T_coeff[i] = P[i];
    }
    return T_coeff;
}
