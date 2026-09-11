#pragma GCC optimize("O3")
#include <iostream>

using namespace std;

int apex_valid_configs = 0;
unsigned long long ALL_ONES;

// Execute hardware-accelerated backtracking
void apex_solve(unsigned long long row_mask, unsigned long long ld_mask, unsigned long long rd_mask) {
    if (row_mask == ALL_ONES) {
        apex_valid_configs++;
        return;
    }

    // Isolate valid bit positions
    unsigned long long valid_positions = ALL_ONES & ~(row_mask | ld_mask | rd_mask);

    // Iterate via hardware bit-stripping (Branchless progression)
    while (valid_positions) {
        // Extract least significant valid bit using CPU Intrinsic __builtin_ctz
        int bit_idx = __builtin_ctzll(valid_positions);
        unsigned long long p = 1ULL << bit_idx;
        valid_positions ^= p; // Fast bit toggle

        // Tail recursion heavily optimized by compiler
        apex_solve(row_mask | p, (ld_mask | p) << 1, (rd_mask | p) >> 1);
    }
}

// Wrapper function to initialize the invariant state
int get_n_queens_apex(int n) {
    ALL_ONES = (n == 64) ? ~0ULL : (1ULL << n) - 1;
    apex_valid_configs = 0;
    apex_solve(0, 0, 0);
    return apex_valid_configs;
}
