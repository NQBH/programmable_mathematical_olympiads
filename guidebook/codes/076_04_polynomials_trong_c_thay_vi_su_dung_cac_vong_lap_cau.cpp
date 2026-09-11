#include <algorithm>
#include <iostream>

using namespace std;

// Evaluates operator bounds dynamically in O(1) space
void evaluate_extended_operator(int n, int k, int m, bool is_integral) {
    int initial_dim = n + 1;

    if (!is_integral) {
        int shift_amount = k * m;
        int ker_dim = min(initial_dim, shift_amount);
        int im_dim = initial_dim - ker_dim;
        cout << "[Derivative] Ker dim: " << ker_dim << ", Im dim: " << im_dim
             << endl;
    } else {
        int shift_amount = k * m;
        int ker_dim = 0; // Integral mapping strictly right-shifts basis
        int im_dim = initial_dim;
        cout << "[Integral] Ker dim: " << ker_dim << ", Im dim: " << im_dim
             << " (Max degree: " << n + shift_amount << ")" << endl;
    }
}
