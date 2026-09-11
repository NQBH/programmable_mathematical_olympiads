#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

struct State {
    double a; // Ty le khach hang cong ty A
    double b; // Ty le khach hang cong ty B
};

// Ma tran chuyen trang thai 2x2
// [a_{n+1}]   [0.7  0.4] [a_n]
// [b_{n+1}] = [0.3  0.6] [b_n]
State step_transition(const State& current) {
    State next;
    next.a = 0.7 * current.a + 0.4 * current.b;
    next.b = 0.3 * current.a + 0.6 * current.b;
    return next;
}

int main() {
    // Ban dau (n = 0): 100% hoc sinh mua banh mi cong ty A
    State current = {1.0, 0.0};

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Giai doan mo phong dong luc hoc Markov:\n";
    std::cout << "Quy 0 (Ban dau): a_0 = " << current.a << ", b_0 = " << current.b << "\n";

    bool dropped_below_50 = false;

    // 18 thang tuong ung voi 6 quy (moi quy 3 thang)
    for (int q = 1; q <= 6; ++q) {
        current = step_transition(current);
        std::cout << "Quy " << q << " (" << q * 3 << " thang): a_" << q 
                  << " = " << current.a << " (" << current.a * 100.0 << "%), b_" 
                  << q << " = " << current.b << " (" << current.b * 100.0 << "%)\n";
        if (current.a < 0.5) {
            dropped_below_50 = true;
        }
    }

    // Kiem tra tiep tuc den 100 quy de kiem chung gioi han dung tieng can
    for (int q = 7; q <= 100; ++q) {
        current = step_transition(current);
        if (current.a < 0.5) {
            dropped_below_50 = true;
        }
    }

    std::cout << "\nTrang thai dung ly thuyet khi k -> vo cung:\n";
    std::cout << "a_inf = 4/7 = " << (4.0 / 7.0) << " (" << (4.0 / 7.0) * 100.0 << "%)\n";
    std::cout << "b_inf = 3/7 = " << (3.0 / 7.0) << " (" << (3.0 / 7.0) * 100.0 << "%)\n";

    if (!dropped_below_50) {
        std::cout << "\nKet luan: Cong ty A khong bao gio co thi phan duoi 50%.\n";
    }

    return 0;
}
