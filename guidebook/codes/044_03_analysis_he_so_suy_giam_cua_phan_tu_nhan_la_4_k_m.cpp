#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// O(1) time bound evaluation for exponential infinite products
void evaluate_infinite_product() {
    double limit = 1.0;

    // Series converges beyond IEEE 754 precision threshold at k ~ 27
    for (int k = 1; k <= 30; ++k) {
        limit *= (1.0 + pow(0.25, k));
    }

    cout << fixed << setprecision(10);
    cout << "Converged Numerical Limit: " << limit << endl;
    cout << "Analytic Upper Bound e^(1/3): " << exp(1.0 / 3.0) << endl;
}
