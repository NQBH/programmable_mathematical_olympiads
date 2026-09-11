#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll power(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// O(d) Lagrange Interpolation for Sum(k^d) evaluated at n
ll interpolate_sum(vector<ll> &y, ll n) {
    int d = y.size() - 1;
    if (n <= d)
        return y[n];

    vector<ll> pref(d + 1, 1), suff(d + 1, 1);
    pref[0] = n % MOD;
    for (int i = 1; i <= d; i++)
        pref[i] = (pref[i - 1] * (n - i)) % MOD;

    suff[d] = (n - d) % MOD;
    for (int i = d - 1; i >= 0; i--)
        suff[i] = (suff[i + 1] * (n - i)) % MOD;

    vector<ll> fact(d + 1, 1);
    for (int i = 1; i <= d; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    ll ans = 0;
    for (int i = 0; i <= d; i++) {
        ll num = 1;
        if (i > 0)
            num = (num * pref[i - 1]) % MOD;
        if (i < d)
            num = (num * suff[i + 1]) % MOD;

        ll den = (fact[i] * fact[d - i]) % MOD;
        if ((d - i) % 2 == 1)
            den = (MOD - den) % MOD;

        ll term = (y[i] * num) % MOD;
        term = (term * power(den, MOD - 2)) % MOD;
        ans = (ans + term) % MOD;
    }
    return ans;
}
