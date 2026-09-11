struct Point {
    long long x, y;
};

__int128_t cross_product(Point O, Point A, Point B) {
    return (__int128_t)(A.x - O.x) * (B.y - O.y) -
           (__int128_t)(A.y - O.y) * (B.x - O.x);
}
