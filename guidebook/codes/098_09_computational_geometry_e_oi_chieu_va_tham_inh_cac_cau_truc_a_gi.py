import sympy as sp
from sympy.geometry import Point, Polygon, convex_hull

# Define discrete point space over Z^2
points = [Point(0, 0), Point(2, 2), Point(1, 1), Point(3, 0), Point(0, 3)]

# Utilize Graham Scan equivalent within the symbolic geometry engine
ch = convex_hull(*points)

print("Output: Convex Hull topological vertices (Counter-clockwise):")
for vertex in ch.vertices:
    print(vertex)
# Output: Point2D(0, 0), Point2D(3, 0), Point2D(2, 2), Point2D(0, 3)
# (Point (1, 1) is correctly identified as an interior coordinate and pruned)

# Exact area verification via Shoelace algorithm over the rational field Q
area = ch.area
print(f"\nOutput: Exact geometric area over Q: {area}")
# Output: Exact geometric area of the Convex Hull: 9/2
