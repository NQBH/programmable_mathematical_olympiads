#include <iostream>
#include <vector>

using namespace std;

// Array-based Convolution for independent random variables
void compute_dice_convolution() {
    int faces = 6;
    vector<double> P(faces + 1, 1.0 / faces); // 1-indexed for clarity
    P[0] = 0;

    vector<double> P_sum(2 * faces + 1, 0.0);

    // Discrete Convolution P(X+Y = n) = Sum P(X=i)*P(Y=n-i)
    for (int i = 1; i <= faces; ++i) {
        for (int j = 1; j <= faces; ++j) {
            P_sum[i + j] += P[i] * P[j];
        }
    }

    cout << "P(Sum = 7): " << P_sum[7] << "\n";
}
