#include <cmath>

bool verify_squeeze(double f_val, double g_val, double h_val,
                    double tol = 1e-9) {
    if (g_val <= f_val && f_val <= h_val) {
        return std::abs(h_val - g_val) < tol;
    }
    return false;
}
