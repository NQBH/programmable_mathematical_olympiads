#include <iostream>
#include <numeric>

using namespace std;
typedef long long ll;

// O(1) space algebraic boundary evaluation
void evaluate_parity_partition(ll a, ll b) {
    ll E = (b / 2) - ((a - 1) / 2);
    if (a < 0 && a % 2 != 0)
        E = (b / 2) - ((a - 1) / 2 - 1); // Exact C++ truncation handling
    ll O = (b - a + 1) - E;

    // Total combinatorial space for 2 elements without replacement
    ll total_space = (E + O) * (E + O - 1) / 2;
    ll same_parity_space = (E * (E - 1) / 2) + (O * (O - 1) / 2);

    if (total_space == 0) {
        cout << "Exact P(same parity): 0/1" << endl;
        return;
    }
    ll gcd_val = std::gcd(same_parity_space, total_space);

    cout << "Exact P(same parity): " << (same_parity_space / gcd_val) << "/"
         << (total_space / gcd_val) << endl;
}
