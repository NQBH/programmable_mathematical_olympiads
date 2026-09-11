import sympy as sp

n = sp.Symbol('n', integer=True)
u = sp.Function('u')

# Establish the homogeneous linear recurrence relation
recurrence_eq = u(n) - 3 * u(n - 1) + 2 * u(n - 2)

# Resolve the system subject to initial boundary conditions
closed_form = sp.rsolve(recurrence_eq, u(n), {u(0): 0, u(1): 1})

print("Output: Closed-form characteristic equation:")
print(sp.simplify(closed_form))
# Output: 2**n - 1

# Formal verification of asymptotic limits
ratio_limit = sp.limit(closed_form.subs(n, n + 1) / closed_form, n, sp.oo)
print(
    f"Output: Asymptotic ratio limit (u(n+1)/u(n)) as n -> infinity: {ratio_limit}")
# Output: 2
