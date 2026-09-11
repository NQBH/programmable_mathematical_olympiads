#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

struct Fraction {
    long long num;
    long long den;

    Fraction(long long n = 0, long long d = 1) {
        if (d < 0) { n = -n; d = -d; }
        long long g = std::gcd(std::abs(n), std::abs(d));
        if (g == 0) g = 1;
        num = n / g;
        den = d / g;
    }

    Fraction operator+(const Fraction& o) const {
        return Fraction(num * o.den + o.num * den, den * o.den);
    }
    Fraction operator*(const Fraction& o) const {
        return Fraction(num * o.num, den * o.den);
    }
};

using Matrix = std::vector<std::vector<Fraction>>;
using Vector = std::vector<Fraction>;

Vector vec_mat_mul(const Vector& v, const Matrix& m) {
    int n = v.size();
    Vector res(n, Fraction(0, 1));
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            res[j] = res[j] + (v[i] * m[i][j]);
        }
    }
    return res;
}

int main() {
    // Ma tran xac suat chuyen giua 4 phong (1-indexed -> 0-indexed)
    Matrix A = {
        {Fraction(0, 1), Fraction(0, 1), Fraction(0, 1), Fraction(1, 1)},
        {Fraction(0, 1), Fraction(0, 1), Fraction(1, 2), Fraction(1, 2)},
        {Fraction(0, 1), Fraction(1, 3), Fraction(0, 1), Fraction(2, 3)},
        {Fraction(1, 4), Fraction(1, 4), Fraction(2, 4), Fraction(0, 1)}
    };

    // Chuot ban dau o phong so 3 (chi so 2)
    Vector X0 = {Fraction(0, 1), Fraction(0, 1), Fraction(1, 1), Fraction(0, 1)};

    Vector X1 = vec_mat_mul(X0, A);
    Vector X2 = vec_mat_mul(X1, A);
    Vector X3 = vec_mat_mul(X2, A);

    std::cout << "Xac suat sau 2 buoc chuyen (X_2):\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "  Phong " << i + 1 << ": " << X2[i].num << "/" << X2[i].den << "\n";
    }
    std::cout << "-> Xac suat o phong 1 sau 2 buoc: " << X2[0].num << "/" << X2[0].den << "\n\n";

    std::cout << "Xac suat sau 3 buoc chuyen (X_3):\n";
    int best_room = 0;
    double max_p = -1.0;
    for (int i = 0; i < 4; ++i) {
        double p = (double)X3[i].num / X3[i].den;
        std::cout << "  Phong " << i + 1 << ": " << X3[i].num << "/" << X3[i].den 
                  << " (" << std::fixed << std::setprecision(4) << p << ")\n";
        if (p > max_p) {
            max_p = p;
            best_room = i + 1;
        }
    }
    std::cout << "-> Kha nang lon nhat sau 3 buoc la o Phong " << best_room << "\n";

    return 0;
}
