from sympy import Matrix, Rational

# Thiet lap ma tran xac suat chuyen giua 4 phong
A = Matrix([
    [Rational(0, 1), Rational(0, 1), Rational(0, 1), Rational(1, 1)],
    [Rational(0, 1), Rational(0, 1), Rational(1, 2), Rational(1, 2)],
    [Rational(0, 1), Rational(1, 3), Rational(0, 1), Rational(2, 3)],
    [Rational(1, 4), Rational(1, 4), Rational(2, 4), Rational(0, 1)]
])

# Vector xac suat ban dau (chuot o phong 3)
X_0 = Matrix([[0, 0, 1, 0]])

# Tinh xac suat sau 2 buoc chuyen
X_2 = X_0 * (A**2)
p_room1_step2 = X_2[0]

print("Phan phoi xac suat sau 2 buoc X_2:", list(X_2))
print("Xac suat chuot o phong 1 sau 2 buoc:", p_room1_step2)

# Tinh xac suat sau 3 buoc chuyen
X_3 = X_0 * (A**3)
print("Phan phoi xac suat sau 3 buoc X_3:", list(X_3))

# Tim phong co xac suat lon nhat
max_val = max(list(X_3))
most_likely_room = list(X_3).index(max_val) + 1

print(f"Xac suat cuc dai tai phong {most_likely_room} voi gia tri: {max_val} (~ {float(max_val):.4f})")

# Kiem chung hinh thuc bang assert
assert p_room1_step2 == Rational(1, 6)
assert X_3[3] == Rational(14, 24) == Rational(7, 12)
assert most_likely_room == 4
print("Kiem chung hinh thuc thiet lap thanh cong.")
