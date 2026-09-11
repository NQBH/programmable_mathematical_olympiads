#include <iostream>
#include <vector>

using namespace std;

// O(d) exact evaluation of m-th antiderivative coefficients
vector<double> multiple_antiderivative(const vector<double> &P, int m) {
    int d = P.size() - 1;
    vector<double> I_P(d + m + 1, 0.0);

    for (int k = 0; k <= d; ++k) {
        if (P[k] == 0)
            continue;

        double factorial_ratio = 1.0;
        // Compute k! / (k+m)! exactly
        for (int i = 1; i <= m; ++i) {
            factorial_ratio /= (k + i);
        }

        I_P[k + m] = P[k] * factorial_ratio;
    }

    return I_P; // The integration constants C_0 ... C_{m-1} default to 0
}
