#include <cmath>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

// Fast Fourier Transform (FFT) execution bounded at O(n log n)
void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    // Isolate polynomial parity (even vs. odd degree separation)
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    // Compute the primitive n-th root of unity in the complex plane
    double angle = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(angle), sin(angle));

    // Exploit the algebraic Cancellation Lemma: w^{k+n/2} = -w^k
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}
