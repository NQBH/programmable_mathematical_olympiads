def find_fixed_point_contraction(T, x0, tol=1e-9, max_iter=1000):
    x = x0
    for _ in range(max_iter):
        x_next = T(x)
        if abs(x_next - x) < tol:
            return x_next
        x = x_next
    raise ValueError("System failed to converge")
