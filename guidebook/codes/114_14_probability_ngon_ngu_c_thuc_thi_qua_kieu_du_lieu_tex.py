import sympy as sp


def verify_markov_fundamental_matrix(n):
    I = sp.eye(n)
    Q = sp.zeros(n)

    for i in range(n):
        Q[i, i] = sp.Rational(i, n)
        if i + 1 < n:
            Q[i, i + 1] = sp.Rational(n - i, n)

    M_mat = (I - Q).inv()
    expected_steps = sum(M_mat[0, :])

    print(f"Output: Exact Rational Expectation for n={n}: {expected_steps}")
    print(f"Output: Evaluated Decimal Form: {expected_steps.evalf(10)}")
    assert expected_steps == sp.Rational(137, 12)


verify_markov_fundamental_matrix(5)
