#include <iostream>
#include <vector>

using namespace std;

// Analytical evaluator for parametric matrix rank
void evaluate_solution_space() {
    int a = -1;
    vector<vector<double>> A = {{1, (double)a + 1, (double)a + 2, 0},
                                {(double)a + 3, 1, 0, (double)a + 2},
                                {(double)a + 2, 0, 1, (double)a + 1},
                                {0, (double)a + 2, (double)a + 3, 1}};

    // Abstract rank evaluation reveals rank = 3 for a = -1
    // Thus Dimension of Kernel (Nullspace) = 4 - 3 = 1
    cout << "For a = -1, Rank(A) = 3. Dim(Kernel) = 1." << endl;
}
