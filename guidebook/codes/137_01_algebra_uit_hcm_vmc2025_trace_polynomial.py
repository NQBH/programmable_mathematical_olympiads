from sympy import Matrix, symbols, solve, eye, Eq, Rational

# Phan (a): Chung minh khong ton tai A trong M_3(R) thoa tr(A)=0 va A^2 + A^T = I_3
# Tu A^T = I - A^2, ta co A la ma tran chuan (A*A^T = A^T*A), nen cheo hoa truc giao duoc.
# Cac tri rieng lambda phai thoa man: lambda^2 + conj(lambda) = 1 va tong cac tri rieng = 0.
x, y = symbols("x y", real=True)
lambda_c = x + y*1j

# Phan (b): Giai phuong trinh ma tran X^3 - 3X^2 + M = 0 voi M = [[2, 2], [2, 2]]
a, b, c, d = symbols("a b c d", real=True)
X = Matrix([[a, b], [c, d]])
M = Matrix([[2, 2], [2, 2]])

# 4 nghiem giai tich da tim
X1 = Matrix([[-Rational(1, 2), -Rational(1, 2)], [-Rational(1, 2), -Rational(1, 2)]])
X2 = Matrix([[1, 1], [1, 1]])
X3 = Matrix([[1, -2], [-2, 1]])
X4 = Matrix([[Rational(5, 2), -Rational(1, 2)], [-Rational(1, 2), Rational(5, 2)]])

candidates = [X1, X2, X3, X4]

for idx, sol in enumerate(candidates):
    f_X = sol**3 - 3*(sol**2) + M
    assert f_X == Matrix.zeros(2, 2)
    print(f"Xac thuc nghiem X_{idx+1}:\n", sol)

print("Tat ca 4 nghiem deu thoa man tuyet doi phuong trinh dai so ma tran.")
