#include <cmath>
#include <iostream>

using namespace std;

// Evaluates local stability of fixed points to determine linearization
// feasibility
void evaluate_conjugacy_stability() {
    double x = 0.5; // Initial state
    double r = 2.5; // Parameter for stable regime

    // Simulate dynamical system u_{n+1} = r * u_n * (1 - u_n)
    for (int i = 0; i < 1000; ++i) {
        x = r * x * (1 - x);
    }

    // Evaluate numerical derivative at the attractor x*
    double derivative = r * (1 - 2 * x);

    if (abs(derivative) > 0 && abs(derivative) != 1.0) {
        cout << "Fixed point is hyperbolic. Local conjugacy exists." << endl;
    } else {
        cout << "Bifurcation boundary. Conjugacy fails." << endl;
    }
}
