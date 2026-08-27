import sympy as sp

# Khoi tao cac bien ky hieu truong abstract
a1, a2, b1, b2, c1, c2 = sp.symbols('a1 a2 b1 b2 c1 c2')
k1, k2, k3 = sp.symbols('k1 k2 k3')

# Bieu dien cot C3 duoi dang ham cua C1, C2 va dieu kien chia het cho 13
# 100*C1 + 10*C2 + C3 = 13*K  =>  C3 = 13*K - 100*C1 - 10*C2
a3 = 13*k1 - 100*a1 - 10*a2
b3 = 13*k2 - 100*b1 - 10*b2
c3 = 13*k3 - 100*c1 - 10*c2

A = sp.Matrix([
    [a1, a2, a3],
    [b1, b2, b3],
    [c1, c2, c3]
])

# Tinh dinh thuc va phan tich thanh nhan tu
det_A = sp.factor(A.det())
print("Dinh thuc cua ma tran A duoi dang dai so:")
print(det_A)
# Output se tu dong rut nhan tu 13 ra ngoai, chung minh det(A) chia het cho 13


if __name__ == '__main__':
    # The script already prints the output globally. 
    pass
