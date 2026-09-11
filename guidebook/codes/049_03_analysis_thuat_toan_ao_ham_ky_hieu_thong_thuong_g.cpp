#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// O(n) isolated evaluation mapping avoiding polynomial expansion
void evaluate_product_derivative(int n, int k) {
    ll derivative_val = 1;

    // Evaluate prod(k - i) for i != k
    for (int i = 1; i <= n; ++i) {
        if (i != k) {
            derivative_val *= (k - i);
        }
    }

    cout << "Exact f'(" << k << ") for roots {1.." << n
         << "} = " << derivative_val << endl;
}
