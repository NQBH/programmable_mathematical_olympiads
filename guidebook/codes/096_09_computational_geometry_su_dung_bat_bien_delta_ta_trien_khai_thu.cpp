#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    long long x, y;
    // Lexicographical sorting prioritized by x-coordinate, followed by
    // y-coordinate
    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// Algebraic Orientation Invariant (Cross Product)
// Returns > 0 for left turn, < 0 for right turn, 0 for collinearity
// Utilize __int128_t to strictly prevent silent 64-bit integer overflow (M >
// 2*10^9)
__int128_t cross_product(Point O, Point A, Point B) {
    return (__int128_t)(A.x - O.x) * (B.y - O.y) -
           (__int128_t)(A.y - O.y) * (B.x - O.x);
}

// Compute Convex Hull strictly avoiding floating-point degradation
vector<Point> convex_hull(vector<Point> &P) {
    int n = P.size(), k = 0;
    if (n <= 2)
        return P;
    vector<Point> H(2 * n);
    sort(P.begin(), P.end());

    // Construct the Lower Hull invariant
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross_product(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    // Construct the Upper Hull invariant
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross_product(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    H.resize(k - 1); // Prune redundant collinear geometries
    return H;
}
