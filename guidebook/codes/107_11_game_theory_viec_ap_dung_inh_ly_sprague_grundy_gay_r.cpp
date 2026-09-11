#include <iostream>
#include <vector>
using namespace std;

// Evaluate mathematical winning states for n independent combinatorial games
// Employ the Sprague-Grundy theorem XOR homomorphism / equivalence
bool isWinningState(const vector<int> &grundy_values) {
    int nim_sum = 0;

    // Utilize bitwise XOR to computationally map state-space convolution
    for (int g : grundy_values) {
        nim_sum ^= g;
    }

    // Boolean classification: State is winning if and only if Nim-sum != 0
    return nim_sum != 0;
}
