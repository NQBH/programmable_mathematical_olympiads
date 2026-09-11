#include <cmath>
#include <iostream>

using namespace std;
typedef double state_t;

// O(n) evaluation of a decoupled non-linear 2nd order system
void evaluate_decoupled_system() {
    int n = 100;
    // System: u_{n+1} = sqrt(u_n * u_{n-1})
    // Conjugacy map: v_n = log(u_n) -> v_{n+1} = 0.5 * v_n + 0.5 * v_{n-1}
    state_t v_prev = log(2.0);
    state_t v_curr = log(8.0);

    for (int i = 2; i <= n; ++i) {
        state_t v_next = 0.5 * v_curr + 0.5 * v_prev;
        v_prev = v_curr;
        v_curr = v_next;
    }

    cout << "Limit of state log-space: " << v_curr << endl;
    cout << "Real space limit u_n: " << exp(v_curr) << endl;
}
