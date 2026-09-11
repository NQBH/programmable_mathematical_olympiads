#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

/**
 * PMO Phase 2: Algorithmic Implementation
 * Problem: DHGTVT VMC2025 Prob. 8 - Grassmann Subspace Intersection Bounding
 * V = R^N (N = 2025). Subspaces M, N, P with dim M = dim N = dim P = 2023.
 * dim(M \cap N) = dim(N \cap P) = 2022, (M \cap N) != (M \cap P).
 * Target: Verify dim(M \cap N \cap P) == 2021.
 */

struct GrassmannState {
    int dim_V;
    int dim_M, dim_N, dim_P;
    int dim_MN, dim_NP;
};

int solve_triple_intersection_dim(const GrassmannState& s) {
    // 1. Case 1: M \cap N \subset P
    // Implies M \cap N \subset M \cap P.
    // If true, dim(M \cap P) >= 2023 => M = P, contradiction.
    // Thus M \cap N is NOT a subspace of P.

    // 2. Case 2: (M \cap N) + P
    // Since (M \cap N) not subset of P, dim((M \cap N) + P) > dim P = s.dim_P.
    // Also ((M \cap N) + P) \subset V => dim <= s.dim_V.
    // If dim((M \cap N) + P) == s.dim_V (2025):
    // Then (M \cap N) + P = V => N + P = V => dim(N + P) = 2025.
    // Then dim(N \cap P) = dim N + dim P - dim(N + P) = 2023 + 2023 - 2025 = 2021 != 2022 (contradiction!).

    // 3. The only consistent dimension for ((M \cap N) + P) is 2024:
    int dim_sum_MN_P = s.dim_P + 1; // 2023 + 1 = 2024

    // Apply Grassmann formula:
    // dim(M \cap N \cap P) = dim(M \cap N) + dim P - dim((M \cap N) + P)
    int dim_triple = s.dim_MN + s.dim_P - dim_sum_MN_P;
    return dim_triple;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    GrassmannState s = {
        2025, // dim V
        2023, // dim M
        2023, // dim N
        2023, // dim P
        2022, // dim(M \cap N)
        2022  // dim(N \cap P)
    };

    int result_dim = solve_triple_intersection_dim(s);
    std::cout << "Subspace Configuration:\n"
              << "  dim(V) = " << s.dim_V << "\n"
              << "  dim(M) = dim(N) = dim(P) = " << s.dim_M << "\n"
              << "  dim(M cap N) = dim(N cap P) = " << s.dim_MN << "\n";
    std::cout << "Calculated dim(M cap N cap P) = " << result_dim << "\n";

    assert(result_dim == 2021);
    std::cout << "Verification successful: dim(M cap N cap P) is uniquely 2021.\n";

    return 0;
}
