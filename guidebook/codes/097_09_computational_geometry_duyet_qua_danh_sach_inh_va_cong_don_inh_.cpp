#include <vector>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

// Double polygon area using __int128_t accumulator to safely handle spiral simple polygons
__int128_t double_polygon_area(const vector<Point> &p) {
    __int128_t area = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        area += (__int128_t)p[i].x * p[(i + 1) % n].y - (__int128_t)p[(i + 1) % n].x * p[i].y;
    }
    return area < 0 ? -area : area;
}
