#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Legendre's formula logic to extract exact powers of primes in n!
// Reduces factorial dependency when transitioning between non-prime modulo
// boundaries
ll count_prime_factors_in_factorial(ll n, ll p) {
    ll count = 0;
    while (n > 0) {
        count += n / p;
        n /= p;
    }
    return count;
}
