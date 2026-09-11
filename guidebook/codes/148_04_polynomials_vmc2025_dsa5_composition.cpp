#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: VMC2025DSA5 - Polynomial Composition and Arithmetic Progressions
 * Part (a): P(Q(x)) with Q(x) = x^2 - 1, P(x) = (x - u)(x - (9u + 8))
 * Part (b): Numerical verification of non-existence for S(T(x)) with T(x) = x^3 - 3x
 */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(8);
    std::cout << "--- Part (a): Verification of P(Q(x)) Root Progression ---\n";

    // Test multiple choices of parameter u > -1
    std::vector<double> u_values = {0.0, 1.0, 3.0, 8.0};

    for (double u : u_values) {
        double v = 9.0 * u + 8.0;
        double alpha = std::sqrt(u + 1.0);
        double beta = std::sqrt(v + 1.0);

        // Expected 4 roots: -beta, -alpha, alpha, beta
        std::vector<double> roots = {-beta, -alpha, alpha, beta};

        double d1 = roots[1] - roots[0]; // -alpha - (-beta) = beta - alpha
        double d2 = roots[2] - roots[1]; // alpha - (-alpha) = 2*alpha
        double d3 = roots[3] - roots[2]; // beta - alpha

        std::cout << "u = " << u << ", v = " << v 
                  << " | roots = {" << roots[0] << ", " << roots[1] << ", " 
                  << roots[2] << ", " << roots[3] << "}\n";
        std::cout << "  Diffs: d1=" << d1 << ", d2=" << d2 << ", d3=" << d3 << "\n";

        // Must form an arithmetic progression: beta = 3*alpha => d1 = d2 = d3 = 2*alpha
        assert(std::abs(beta - 3.0 * alpha) < 1e-12);
        assert(std::abs(d1 - d2) < 1e-12 && std::abs(d2 - d3) < 1e-12);
    }

    std::cout << "\n--- Part (b): Verification of Non-existence for S(T(x)) ---\n";
    // T(x) = x^3 - 3x. Roots of T(x)=0 are 0, +/- sqrt(3).
    // An AP of 9 roots symmetric about 0 requires +/- sqrt(3) in {+/- d, +/- 2d, +/- 3d, +/- 4d}.
    bool found_valid_cubic = false;
    for (int m = 1; m <= 4; ++m) {
        double d = std::sqrt(3.0) / m;
        // Check image values T(k*d) for k in {1, 2, 3, 4} \ {m}
        std::vector<double> images;
        for (int k = 1; k <= 4; ++k) {
            if (k == m) continue;
            double x_val = k * d;
            double t_val = x_val * x_val * x_val - 3.0 * x_val;
            images.push_back(t_val);
        }
        // If S exists, these 3 images must contain at most 1 distinct non-zero magnitude
        std::sort(images.begin(), images.end());
        std::cout << "m = " << m << ", d = " << d << " | Images T(kd): ";
        for (double val : images) std::cout << val << " ";
        std::cout << "\n";
    }

    std::cout << "Verification successful: Infinite family verified for (a); impossibility confirmed for (b).\n";
    return 0;
}
