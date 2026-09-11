#include <iostream>
#include <vector>

using namespace std;

// O(k * d) DP formulation for Newton's Sums of powers
void compute_newton_sums() {
    int degree = 4;
    // P(x) = x^4 - 2x^3 + 0x^2 + 0x - 1
    // Coefficients of x^{d-1}, x^{d-2}, etc. inverted signs
    vector<double> e = {2, 0, 0, 1}; // Elementary symmetric polynomials

    vector<double> S(4, 0);                      // Stores S_0 to S_3
    S[0] = 4;                                    // Degree
    S[1] = e[0];                                 // 2
    S[2] = e[0] * S[1] - 2 * e[1];               // 2*2 - 0 = 4
    S[3] = e[0] * S[2] - e[1] * S[1] + 3 * e[2]; // 2*4 - 0 + 0 = 8

    cout << "Sum of cubes S_3: " << S[3] << endl;
}
