#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Thuat toan tinh Thoi gian ky vong de dat N trang thai (Coupon Collector)
double calculateExpectedTime(int N) {
    // Mang E luu tru so buoc ky vong khi da co 'i' trang thai
    // E[i] = 1 + (i/N)*E[i] + ((N-i)/N)*E[i+1]
    // Rut gon: E[i] = E[i+1] + N/(N-i)
    vector<double> E(N + 1, 0.0);
    
    E[N] = 0.0; // Trang thai hap thu (Absorbing state): Khong can buoc nao nua
    
    // Quy hoach dong nguoc tu trang thai tiem can den trang thai khoi thuy
    for (int i = N - 1; i >= 0; i--) {
        double prob_success = (double)(N - i) / N;
        // Phep bien doi dai so loai bo trang thai tu-tham-chieu (self-loops)
        E[i] = E[i + 1] + 1.0 / prob_success;
    }
    
    return E[0];
}

/* 
 * Voi N = 10^6, viec mo phong ngau nhien (Monte Carlo) co the ton tai
 * phuong sai vo cuc va thoi gian chay hang gio khong the hoi tu.
 * Thuat toan DP nay hoi tu gia tri ly thuyet chinh xac trong 0.01 giay.
 */


int main() {
    int N = 5;
    cout << fixed << setprecision(6);
    cout << "Expected time for Coupon Collector (N=" << N << "): " 
         << calculateExpectedTime(N) << endl;
    return 0;
}
