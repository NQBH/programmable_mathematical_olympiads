#include <cmath>
#include <iostream>

using namespace std;

// Constraint verifier for nilpotent matrix Taylor expansions
void verify_nilpotent_expansion() {
    double x = M_PI / 2.0;

    // Evaluate theoretical off-diagonal value y * cos(x)
    double cos_val = cos(x);

    if (abs(cos_val) < 1e-15) {
        cout << "Algebraic contradiction confirmed. Off-diagonal must be 0."
             << endl;
    }
}
