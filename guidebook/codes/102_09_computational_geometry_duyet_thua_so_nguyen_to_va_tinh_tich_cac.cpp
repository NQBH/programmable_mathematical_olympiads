long long compute_tau(long long n) {
    long long count = 1;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            int exponent = 0;
            while (n % p == 0) {
                exponent++;
                n /= p;
            }
            count *= (exponent + 1);
        }
    }
    if (n > 1)
        count *= 2;
    return count;
}
