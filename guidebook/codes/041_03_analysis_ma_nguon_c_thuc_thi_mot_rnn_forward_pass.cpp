#include <cmath>
#include <iostream>

using namespace std;
typedef double neural_state;

// Hyperbolic tangent activation mirroring non-linear recurrences
neural_state tanh_activation(neural_state x) { return tanh(x); }

// O(n) evaluation of RNN matching recurrent sequence iteration
void simulate_rnn_sequence() {
    int time_steps = 100;
    double W = 0.9; // Transition weight (Multiplier)
    double U = 0.1; // Forcing weight

    neural_state h = 0.0; // Initial state

    for (int t = 1; t <= time_steps; ++t) {
        double input_t = sin(t); // Time-dependent forcing sequence
        h = tanh_activation(W * h + U * input_t);
    }

    cout << "Hidden state (sequence value) at t=100: " << h << endl;
}
