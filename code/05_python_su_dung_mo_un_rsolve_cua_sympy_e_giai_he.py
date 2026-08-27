import sympy as sp

n = sp.Symbol('n', integer=True)
u = sp.Function('u')

# Thiet lap phuong trinh sai phan: u(n) - 3u(n-1) + 2u(n-2) = 0
recurrence_eq = u(n) - 3*u(n-1) + 2*u(n-2)

# Giai he voi dieu kien bien (Boundary conditions)
closed_form = sp.rsolve(recurrence_eq, u(n), {u(0): 0, u(1): 1})

print("Cong thuc dang dong (Closed-form) cua day so:")
print(sp.simplify(closed_form))
# Output: 2**n - 1

# Kiem chung gioi han tiem can (Asymptotic behavior)
ratio_limit = sp.limit(closed_form.subs(n, n+1) / closed_form, n, sp.oo)
print(f"Gioi han ty so u(n+1)/u(n) khi n -> oo: {ratio_limit}")
# Output: 2


if __name__ == '__main__':
    pass
