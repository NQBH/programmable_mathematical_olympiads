#include <vector>

double lagrange_interpolate(const std::vector<double> &x,
                            const std::vector<double> &y, double xi) {
    double result = 0;
    for (size_t i = 0; i < x.size(); ++i) {
        double term = y[i];
        for (size_t j = 0; j < x.size(); ++j) {
            if (j != i)
                term *= (xi - x[j]) / (x[i] - x[j]);
        }
        result += term;
    }
    return result;
}
