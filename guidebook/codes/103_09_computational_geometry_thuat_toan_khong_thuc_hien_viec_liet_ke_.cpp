#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Extract prime factorization exponents
vector<int> get_prime_exponents(ll a) {
    vector<int> exponents;
    for (ll p = 2; p * p <= a; ++p) {
        if (a % p == 0) {
            int count = 0;
            while (a % p == 0) {
                count++;
                a /= p;
            }
            exponents.push_back(count);
        }
    }
    if (a > 1)
        exponents.push_back(1);
    return exponents;
}

// O(sqrt(a)) analytical probability evaluation bypassing divisor enumeration
void evaluate_area_invariant(ll a) {
    vector<int> exps = get_prime_exponents(a);

    ll num = 1, den = 1;
    for (int exp : exps) {
        num *= (2 * exp + 1);
        den *= (exp + 1) * (exp + 1);
    }

    cout << "Exact Probability P(gcd(b,c)=1) = " << num << "/" << den << endl;
}
