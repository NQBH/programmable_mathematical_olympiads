#include <cmath>

bool is_critical_point(double df_c, double tol = 1e-9) {
    // Kiem dinh diem toi han bang xap xi sai so 0
    return std::abs(df_c) < tol;
}
