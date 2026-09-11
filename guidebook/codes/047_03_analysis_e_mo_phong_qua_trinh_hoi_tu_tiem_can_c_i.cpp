#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

// Epsilon-delta convergence simulator for hybrid continuous-discrete bounds
void evaluate_squeeze_limit() {
    double epsilon = 1.0;

    cout << fixed << setprecision(6);
    for (int step = 1; step <= 8; ++step) {
        epsilon /= 10.0; // x -> 0

        long long N = floor(1.0 / abs(epsilon));
        double S = (double)N * (N + 1) / 2.0;

        double limit_val = (epsilon * epsilon) * S;

        cout << "x = 10^-" << step << " | f(x) = " << limit_val << endl;
    }
    cout << "Analytic Squeeze Theorem Limit: 0.5" << endl;
}
