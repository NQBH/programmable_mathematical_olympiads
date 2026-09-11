import sympy as sp

z = sp.Symbol('z')
n = 6

# Factorize z^n - 1 into irreducible cyclotomic polynomials over Q
polynomial = z**n - 1
factors = sp.factor(polynomial)

print(f"Output: Irreducible cyclotomic factorization of z^{n} - 1:")
print(factors)
# Output: (z - 1)*(z + 1)*(z**2 - z + 1)*(z**2 + z + 1)

# Symbolically extract the exact roots of unity
roots = sp.solve(polynomial, z)
print(f"\nOutput: Exact {n}-th roots of unity (Complex Plane):")
for r in roots:
    # Output strict structural representations via Euler's identity
    print(sp.simplify(r))
