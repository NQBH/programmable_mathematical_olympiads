import sympy as sp

a = sp.Symbol('a')
M = sp.Matrix([
    [a, 2023, 2024, 2025],
    [2025, 2024, 2023, a],
    [2024, 2025, a, 2023],
    [2023, a, 2025, 2024]
])

det_M = M.det()
print("Dinh thuc cua M(a) la:")
print(sp.factor(det_M)) 
# Output xac nhan phan tich o Giai doan 1 (ton tai nhan tu a + 6072)


if __name__ == '__main__':
    # Test for matrix rank and factorization
    M = sp.Matrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    print("Rank:", M.rank())
