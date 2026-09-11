from sympy import Matrix, symbols, eye, simplify

# Bai 11: Kiem chung cong thuc dong A^n
A = Matrix([
    [2, 0, 0],
    [0, 3, 0],
    [0, 1, 2]
])

# Cheo hoa ma tran hoac su dung ma tran luy dang B
B = Matrix([
    [0, 0, 0],
    [0, 1, 0],
    [0, 1, 0]
])

assert B**2 == B # B luy dang
assert A == 2 * eye(3) + B

# Tinh luy thua thong qua dang chuan Jordan
P, J = A.jordan_form()
n = symbols("n", integer=True, positive=True)

# Cong thuc dong ly thuyet
A_n_theoretical = Matrix([
    [2**n, 0, 0],
    [0, 3**n, 0],
    [0, 3**n - 2**n, 2**n]
])

# Kiem chung voi n cu the n = 1, 2, 3, 4, 5
for val in range(1, 6):
    assert (A**val) == A_n_theoretical.subs(n, val)
print("Bai 11: Cong thuc luy thua A^n xac thuc thanh cong.")

# Bai 12: Chung minh A^2 = tr(A)*A cho moi ma tran hang 1
u1, u2, u3 = symbols("u1 u2 u3")
v1, v2, v3 = symbols("v1 v2 v3")
u = Matrix([u1, u2, u3])
v = Matrix([v1, v2, v3])

# Ma tran hang 1 dang u * v^T
R = u * v.T
assert R.rank() == 1

# Kiem tra dong nhat thuc R^2 - tr(R)*R == 0
tr_R = R.trace()
R_diff = simplify(R**2 - tr_R * R)
assert R_diff == Matrix.zeros(3, 3)

print(f"Bai 12: Dong nhat thuc R^2 = tr(R)*R voi tr(R) = {tr_R} duoc chung minh tong quat.")
