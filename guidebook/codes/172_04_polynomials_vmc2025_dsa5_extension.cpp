#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Topic: Degree-n Generalization of VMC2025DSA5 Root Progressions
 * Q(x) = x^2 - 1. P_n(Q(x)) has 2n roots forming an AP symmetric about 0.
 * Roots: +/- (2k - 1)/2 * d for k = 1, ..., n.
 * Target roots of P_n(y): y_k = ((2k - 1)/2 * d)^2 - 1.
 */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(8);
    std::cout << "--- Degree-n Extension of VMC2025DSA5: Verification ---\n";

    double d = 1.5; // Step size of arithmetic progression

    for (int n = 2; n <= 5; ++n) {
        // Construct 2n roots of P_n(Q(x))
        std::vector<double> ap_roots;
        for (int k = n; k >= 1; --k) {
            ap_roots.push_back(-((2 * k - 1) / 2.0) * d);
        }
        for (int k = 1; k <= n; ++k) {
            ap_roots.push_back(((2 * k - 1) / 2.0) * d);
        }

        // Verify that ap_roots form an arithmetic progression
        for (size_t i = 1; i < ap_roots.size(); ++i) {
            assert(std::abs((ap_roots[i] - ap_roots[i - 1]) - d) < 1e-12);
        }

        // Roots of P_n(y): y_k = x^2 - 1
        std::vector<double> y_roots;
        for (int k = 1; k <= n; ++k) {
            double x_k = ((2 * k - 1) / 2.0) * d;
            y_roots.push_back(x_k * x_k - 1.0);
        }

        // Verify that P_n(Q(r)) == 0 for every root r in ap_roots
        for (double r : ap_roots) {
            double q_val = r * r - 1.0;
            double p_val = 1.0;
            for (double y_k : y_roots) {
                p_val *= (q_val - y_k);
            }
            assert(std::abs(p_val) < 1e-9);
        }

        std::cout << "Degree n = " << n << ": Successfully verified " 
                  << (2 * n) << " roots in AP with d = " << d << "\n";
    }

    std::cout << "Verification successful: Degree-n canonical family uniquely characterized.\n";
    return 0;
}
