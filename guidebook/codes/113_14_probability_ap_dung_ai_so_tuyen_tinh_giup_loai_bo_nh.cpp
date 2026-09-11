#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

// Compute expected absorption time for an n-state Markov chain
double calculateExpectedTime(int n) {
    // Vector E stores exact expected transitions from state i
    // E[i] = 1 + (i/n)*E[i] + ((n-i)/n)*E[i+1]
    // Analytic reduction: E[i] = E[i+1] + n/(n-i)
    vector<double> E(n + 1, 0.0);

    E[n] = 0.0; // Terminal absorbing state: Stochastic transition ceases

    // Reverse dynamic programming from terminal state to origin
    for (int i = n - 1; i >= 0; i--) {
        double prob_success = (double)(n - i) / n;
        // Mathematical manipulation formally eliminates self-referential loops
        E[i] = E[i + 1] + 1.0 / prob_success;
    }

    return E[0];
}

/*
 * Voi n = 10^6, viec mo phong ngau nhien (Monte Carlo) co the ton tai
 * phuong sai vo cuc va thoi gian chay hang gio khong the hoi tu.
 * Thuat toan DP nay hoi tu gia tri ly thuyet chinh xac trong 0.01 giay.
 */
