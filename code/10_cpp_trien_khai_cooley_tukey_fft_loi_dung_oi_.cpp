#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);

// Thuat toan Bien doi Fourier Nhanh (FFT) voi do phuc tap O(N log N)
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    // Phan ly da thuc theo bac chan (even) va bac le (odd)
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    // Xac dinh goc pha co ban (Primitive root of unity)
    double angle = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(angle), sin(angle));

    // Khai thac Bo de triet tieu: w^{k+N/2} = -w^k
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}


int main() {
    vector<cd> poly = {1, 2, 3, 4}; // Polynomial 1 + 2x + 3x^2 + 4x^3
    fft(poly, false);
    cout << "FFT Evaluation:" << endl;
    for(int i = 0; i < poly.size(); i++) {
        cout << "w^" << i << " -> " << poly[i] << endl;
    }
    return 0;
}
