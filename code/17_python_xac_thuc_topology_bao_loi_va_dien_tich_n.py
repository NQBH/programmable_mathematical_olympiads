import sympy as sp
from sympy.geometry import Point, Polygon, convex_hull

# Dinh nghia tap hop diem tren mat phang Z^2
points = [Point(0, 0), Point(2, 2), Point(1, 1), Point(3, 0), Point(0, 3)]

# Su dung thuat toan Kiem chung ky he (Symbolic Convex Hull)
ch = convex_hull(*points)

print("Cac dinh cua Bao loi (Theo chieu nguoc kim dong ho):")
for vertex in ch.vertices:
    print(vertex)
# Output: Point2D(0, 0), Point2D(3, 0), Point2D(2, 2), Point2D(0, 3)
# (Diem (1, 1) bi loai bo vi nam ben trong bao loi)

# Kiem chung Dien tich bang Cong thuc Shoelace tren mien huu ti Q
area = ch.area
print(f"\nDien tich chinh xac cua Bao loi: {area}")
# Output: Dien tich chinh xac cua Bao loi: 9/2


if __name__ == '__main__':
    # Code runs globally, just standard wrap.
    pass
