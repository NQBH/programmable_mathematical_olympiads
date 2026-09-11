import sympy as sp

a = sp.Symbol('a')
M = sp.Matrix([
    [a, 2023, 2024, 2025],
    [2025, 2024,
     2023, a],
    [2024, 2025,
     a, 2023],
    [2023, a,
     2025, 2024]
])

det_M = M.det()
print("Output: Algebraic factorization of det(M):")
print(sp.factor(det_M))
# Output formally verifies Phase 1 algebraic derivation (confirms
# invariant a + 6072)
