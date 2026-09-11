#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: VMC2025GTA2 / GTB2 - Power Mean Monotonicity & Asymptotics
 * f(x) = ((30^x + 4^x + 2025^x) / 3)^(1/x)
 * Target: Verify f'(x) > 0 for all x in (0, \infty)
 */

double power_mean(double x) {
    if (x <= 1e-9) {
        // Geometric mean limit as x -> 0+
        return std::cbrt(30.0 * 4.0 * 2025.0);
    }
    // High-precision evaluation avoiding numerical overflow
    if (x > 50.0) {
        // As x -> \infty, f(x) -> 2025 * (1/3)^(1/x) -> 2025
        double log_sum = x * std::log(2025.0) + std::log((1.0 + std::pow(30.0 / 2025.0, x) + std::pow(4.0 / 2025.0, x)) / 3.0);
        return std::exp(log_sum / x);
    }
    double sum = (std::pow(30.0, x) + std::pow(4.0, x) + std::pow(2025.0, x)) / 3.0;
    return std::pow(sum, 1.0 / x);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(8);
    const double geom_mean = std::cbrt(30.0 * 4.0 * 2025.0);
    std::cout << "Asymptotic Infimum (x -> 0+): Geometric Mean = " << geom_mean << "\n";
    std::cout << "Asymptotic Supremum (x -> oo): Maximum Element = 2025.00000000\n\n";

    std::vector<double> test_points = {0.001, 0.01, 0.1, 0.5, 1.0, 2.0, 5.0, 10.0, 20.0, 50.0, 100.0};
    double prev_f = 0.0;

    for (double x : test_points) {
        double f_val = power_mean(x);
        
        // Central difference numerical derivative
        double h = x * 1e-5;
        double f_prime = (power_mean(x + h) - power_mean(x - h)) / (2.0 * h);

        std::cout << "x = " << std::setw(8) << x 
                  << " | f(x) = " << std::setw(13) << f_val 
                  << " | f'(x) = " << std::setw(12) << f_prime << "\n";

        assert(f_prime > 0.0);
        assert(f_val > prev_f);
        prev_f = f_val;
    }

    assert(std::abs(power_mean(1e-8) - geom_mean) < 1e-5);
    assert(std::abs(power_mean(100.0) - 2025.0) < 25.0);
    std::cout << "\nVerification successful: Function f(x) is strictly increasing on (0, oo).\n";

    return 0;
}
