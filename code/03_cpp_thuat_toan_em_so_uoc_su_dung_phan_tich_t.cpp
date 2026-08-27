#include <iostream>
using namespace std;

long long countDiophantineSolutions(long long N) {
    long long total_solutions = 1;
    long long temp = N;
    
    // Su dung Toan hoc de khoa khong gian tim kiem o tiem can O(sqrt(N))
    for (long long i = 2; i * i <= temp; ++i) { 
        if (temp % i == 0) {
            long long count = 0;
            while (temp % i == 0) {
                count++;
                temp /= i;
            }
            // Su dung tinh chat to hop d(N^2) = (2a_1 + 1)(2a_2 + 1)...
            total_solutions *= (2 * count + 1);
        }
    }
    // Xu ly thua so nguyen to cuoi cung
    if (temp > 1) {
        total_solutions *= 3; 
    }
    return total_solutions;
}


int main() {
    long long N = 360;
    cout << "Number of divisors of " << N << " is: " << countDiophantineSolutions(N) << endl;
    return 0;
}
