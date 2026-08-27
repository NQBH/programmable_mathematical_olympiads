import sympy as sp

z = sp.Symbol('z')
N = 6

# Phan tich z^N - 1 thanh cac Da thuc chia duong tron bat kha quy tren Q
polynomial = z**N - 1
factors = sp.factor(polynomial)

print(f"Phan tich kieu kien truc (Factorization) cua z^{N} - 1:")
print(factors)
# Output: (z - 1)*(z + 1)*(z**2 - z + 1)*(z**2 + z + 1)

# Giai va truy xuat truc tiep dang ky hieu cua Can don vi
roots = sp.solve(polynomial, z)
print(f"\nCac can bac {N} cua don vi (Roots of unity):")
for r in roots:
    # Bieu dien ket qua duoi dang cong thuc Euler chinh xac
    print(sp.simplify(r))


if __name__ == '__main__':
    # Script already executes globally.
    pass
