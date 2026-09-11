#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// O(n) Dynamic Programming recurrence for high-order derivatives
void evaluate_arctan_derivative(int n, double x) {
    vector<double> f_dev(n + 1, 0);
    f_dev[0] = atan(x);
    f_dev[1] = 1.0 / (1.0 + x * x);

    for (int k = 2; k <= n; ++k) {
        double term1 = 2 * (k - 1) * x * f_dev[k - 1];
        double term2 = (k - 2) * (k - 1) * f_dev[k - 2];
        f_dev[k] = -(term1 + term2) / (1.0 + x * x);
    }

    cout << "Derivative f^(" << n << ") at x=" << x << " : " << f_dev[n]
         << endl;
}
