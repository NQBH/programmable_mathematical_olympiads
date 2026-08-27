#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;
    // Sap xep tu dien (Lexicographical sort) uu tien x, sau do y
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// Bat bien Dinh huong (Cross Product Invariant)
// Tra ve > 0 neu re trai, < 0 neu re phai, 0 neu thang hang
long long cross_product(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Xay dung Bao loi khong dung so Float
vector<Point> convex_hull(vector<Point>& P) {
    int n = P.size(), k = 0;
    if (n <= 3) return P;
    vector<Point> H(2 * n);
    sort(P.begin(), P.end());

    // Xay dung Bao duoi (Lower Hull)
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross_product(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    // Xay dung Bao tren (Upper Hull)
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross_product(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    H.resize(k - 1); // Loai bo diem trung lap
    return H;
}


int main() {
    vector<Point> P = {{0, 0}, {2, 2}, {1, 1}, {3, 0}, {0, 3}};
    vector<Point> hull = convex_hull(P);
    cout << "Convex Hull Vertices:" << endl;
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
    return 0;
}
