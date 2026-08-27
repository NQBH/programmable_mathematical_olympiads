import sympy as sp

def verify_markov_fundamental_matrix(N):
    # Khai bao Ma tran Don vi I va Ma tran Chuyen Q (Transient Matrix)
    I = sp.eye(N)
    Q = sp.zeros(N)
    
    # Kien tao Topology xac suat: Q[i, i] = i/N, Q[i, i+1] = (N-i)/N
    for i in range(N):
        Q[i, i] = sp.Rational(i, N)
        if i + 1 < N:
            Q[i, i+1] = sp.Rational(N - i, N)
            
    # Dinh ly Markov: Ma tran Co ban N_mat = (I - Q)^(-1)
    # Su dung So Huu Ti (Rational) de triet tieu sai so float cua may tinh
    N_mat = (I - Q).inv()
    
    # Ky vong so buoc E[0] chinh la tong cua hang dau tien trong N_mat
    expected_steps = sum(N_mat[0, :])
    
    print(f"Gia tri Ky vong nguyen thuy (Exact Rational) cho N={N}:")
    print(expected_steps)
    
    # Tinh gia tri xap xi thap phan de doi chieu voi C++
    print(f"Gia tri Thap phan bieu kien (Decimal Form): {expected_steps.evalf(10)}")

verify_markov_fundamental_matrix(5)
# Output: Gia tri Ky vong nguyen thuy: 137/12
# Gia tri Thap phan bieu kien: 11.41666667


if __name__ == '__main__':
    verify_markov_fundamental_matrix(5)
    verify_markov_fundamental_matrix(6)
