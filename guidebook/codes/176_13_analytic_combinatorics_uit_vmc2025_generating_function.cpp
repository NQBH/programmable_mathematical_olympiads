#include <iostream>
#include <vector>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: UIT VMC2025 Combinatorics - Marble Selection via Generating Functions
 * Conditions:
 *   Red: even => G_red(x) = 1 / (1 - x^2)
 *   Orange: multiple of 7 => G_orange(x) = 1 / (1 - x^7)
 *   Yellow: <= 6 => G_yellow(x) = (1 - x^7) / (1 - x)
 *   Green: <= 4 => G_green(x) = (1 - x^5) / (1 - x)
 * Total G(x) = (1 - x^5) / ((1 - x^2)*(1 - x)^2)
 * Closed form: [x^n] G(x) = (10*n - 5 + (-1)^n) / 4 for n >= 2.
 * Target: [x^2025] = (20250 - 5 - 1) / 4 = 5061.
 */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "--- UIT VMC2025: Marble Selection Generating Function ---\n";

    int N = 2025;

    // Direct coefficient evaluation of H(x) = 1 / ((1 - x^2)(1 - x)^2)
    // h[n] = sum_{j=0}^{floor(n/2)} (n - 2*j + 1)
    std::vector<long long> h(N + 1, 0);
    for (int n = 0; n <= N; ++n) {
        long long m = n / 2;
        h[n] = (m + 1) * (n + 1) - 2 * (m * (m + 1) / 2);
    }

    // G(x) = (1 - x^5) * H(x)
    std::vector<long long> g(N + 1, 0);
    for (int n = 0; n <= N; ++n) {
        g[n] = h[n] - (n >= 5 ? h[n - 5] : 0);
    }

    // Verify against theoretical closed-form formula for n >= 2
    for (int n = 2; n <= N; ++n) {
        long long sign = (n % 2 == 0) ? 1 : -1;
        long long expected = (10LL * n - 5LL + sign) / 4LL;
        assert(g[n] == expected);
    }

    std::cout << "Closed-form formula verified for all n in [2, 2025].\n";
    std::cout << "Calculated [x^2025] G(x) = " << g[2025] << " (Expected: 5061)\n";
    assert(g[2025] == 5061);

    std::cout << "Verification successful: Exactly 5061 valid marble selections exist.\n";
    return 0;
}
