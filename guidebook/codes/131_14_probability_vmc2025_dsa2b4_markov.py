from sympy import Matrix, Rational, symbols, limit, oo

# Khai bao ma tran xac suat chuyen P
P = Matrix([
    [Rational(7, 10), Rational(4, 10)],
    [Rational(3, 10), Rational(6, 10)]
])

# Vector trang thai ban dau x_0 = [1, 0]^T
x_0 = Matrix([1, 0])

# Cheo hoa ma tran: P = V * D * V^(-1)
V, D = P.diagonalize()

print("Ma tran tri rieng D:\n", D)
print("Ma tran vector rieng V:\n", V)

# Tinh luy thua bac n ky hieu P^n
n = symbols("n", integer=True, positive=True)
D_n = Matrix([
    [D[0, 0]**n, 0],
    [0, D[1, 1]**n]
])
P_n = V * D_n * V.inv()

# Vector trang thai tai quy thu n
x_n = P_n * x_0
a_n = x_n[0]
b_n = x_n[1]

print(f"Cong thuc dong ty le cong ty A: a_n = {a_n}")
print(f"Cong thuc dong ty le cong ty B: b_n = {b_n}")

# Gia tri sau 18 thang (n = 6 quy)
a_6 = a_n.subs(n, 6)
b_6 = b_n.subs(n, 6)

print(f"a_6 (Phan so chinh xac) = {a_6} ~ {float(a_6):.6f}")
print(f"b_6 (Phan so chinh xac) = {b_6} ~ {float(b_6):.6f}")

# Chung minh gioi han dung
a_inf = limit(a_n, n, oo)
print(f"Gioi han thi phan cong ty A khi n -> oo: {a_inf} ~ {float(a_inf):.6f}")

# Kiem chung hinh thuc
assert a_inf == Rational(4, 7)
assert a_6 > Rational(1, 2)
assert a_inf > Rational(1, 2)
print("Kiem chung thanh cong toan bo tinh chat hoi tu.")
