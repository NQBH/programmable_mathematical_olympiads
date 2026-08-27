#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000005; // Giai quyet N = 10^7 trong micro-giay
int phi[MAXN];
vector<int> primes;
bool is_prime[MAXN];

// Thuat toan Sang tuyen tinh O(N) tien xu ly Ham nhan tinh
void linearSieve(int n) {
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    phi[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            phi[i] = i - 1; // Tinh chat: neu p nguyen to, phi(p) = p-1
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            // Xung dot chia het: Ap dung tinh chat ham nhan tinh (Multiplicative property)
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break; // Dam bao moi hop so chi duoc sang 1 lan duy nhat (O(N) Strict)
            } else {
                phi[i * p] = phi[i] * phi[p];
            }
        }
    }
}

// Xy ly Tong Dirichlet da duoc nghich dao
long long calculateGCDSum(int N) {
    long long total_sum = 0;
    for (int d = 1; d <= N; d++) {
        long long count = N / d;
        total_sum += phi[d] * count * count;
    }
    return total_sum;
}


int main() {
    int N = 100;
    linearSieve(N);
    cout << "Sum of GCD(i, j) for 1 <= i,j <= " << N << " is: " << calculateGCDSum(N) << endl;
    return 0;
}
