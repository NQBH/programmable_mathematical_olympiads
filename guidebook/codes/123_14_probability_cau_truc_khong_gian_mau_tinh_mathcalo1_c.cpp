#include <iostream>
#include <numeric>

using namespace std;

// O(1) constrained discrete space evaluation
void evaluate_consecutive_dice_events(int target_sum) {
    int sum_matches = 0;
    int divisor_matches = 0;
    int total_space = 36;

    for (int d1 = 1; d1 <= 6; ++d1) {
        for (int d2 = 1; d2 <= 6; ++d2) {
            if (d1 + d2 == target_sum)
                sum_matches++;
            if (d2 % d1 == 0 || d1 % d2 == 0)
                divisor_matches++;
        }
    }

    int g_sum = std::gcd(sum_matches, total_space);
    cout << "P(Sum=" << target_sum << ") = " << sum_matches / g_sum << "/"
         << total_space / g_sum << endl;

    int g_div = std::gcd(divisor_matches, total_space);
    cout << "P(One divides another) = " << divisor_matches / g_div << "/"
         << total_space / g_div << endl;
}
