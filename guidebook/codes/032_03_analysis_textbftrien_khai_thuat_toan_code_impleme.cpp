bool verify_wilson(int p) {
    if (p < 2)
        return false;
    long long fact = 1;
    for (int i = 2; i < p; ++i)
        fact = (fact * i) % p;
    return fact == p - 1;
}
