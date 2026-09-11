#include <iostream>

using namespace std;

// O(1) space and time complexity for Diophantine geometric partitioning
void evaluate_perimeter_invariant(int n) {
    if (n < 2) {
        cout << "N is too small for positive integer partitions." << endl;
        return;
    }

    // Part (a): Positive integer domain N*
    int sample_space_a = n - 1;
    int square_count = (n % 2 == 0) ? 1 : 0;

    cout << "Domain N*: P(Square) = " << square_count << "/" << sample_space_a
         << endl;

    // Strict rectangles (excluding squares)
    int strict_rectangles = sample_space_a - square_count;
    cout << "Domain N*: P(Strict Rectangle) = " << strict_rectangles << "/"
         << sample_space_a << endl;
}
