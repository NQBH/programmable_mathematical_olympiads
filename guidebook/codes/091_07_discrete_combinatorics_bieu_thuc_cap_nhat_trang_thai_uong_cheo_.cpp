#include <iostream>
using namespace std;

int total_configurations = 0;
int limit; // Define strict bitmask boundary for n columns

// Recursive branch pruning via Boolean algebraic invariants
void solve(int col, int diag1, int diag2) {
    if (col == limit) {
        total_configurations++; // Complete structural placement of n queens
                                // achieved
        return;
    }

    // Isolate all mathematically valid column positions (bits == 1)
    int pos = limit & (~(col | diag1 | diag2));

    while (pos) {
        // Extract the least significant valid bit via 2's complement arithmetic
        int p = pos & (-pos);
        pos -= p; // Execute bitwise toggle to progress combinatorial search

        // Recurse to subsequent level; bitwise shifts map to r+c and r-c
        // invariants
        solve(col | p, (diag1 | p) << 1, (diag2 | p) >> 1);
    }
}

int countNQueens(int n) {
    limit = (1 << n) - 1;
    total_configurations = 0;
    solve(0, 0, 0);
    return total_configurations;
}
