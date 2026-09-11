#include <iostream>
#include <vector>

using namespace std;

// O(n) evaluation of high-order derivative operator via array shifting
void evaluate_spectral_derivative() {
    int max_degree = 2023;
    int derivative_order = 2 * 870; // 1740

    int dim_V = max_degree + 1;                 // 2024
    int dim_Ker = min(dim_V, derivative_order); // 1740
    int dim_Im = dim_V - dim_Ker;               // 284

    cout << "Dimension of Ker(g): " << dim_Ker << endl;
    cout << "Dimension of Im(g): " << dim_Im << endl;
}
