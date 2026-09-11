long long count_compositions(int n, int k) {
    if (k < 1 || n < k)
        return 0;
    long long res = 1;
    for (int i = 1; i <= k - 1; ++i) {
        res = res * (n - i) / i;
    }
    return res;
}
