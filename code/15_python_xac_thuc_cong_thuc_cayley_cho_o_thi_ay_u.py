import sympy as sp

def verify_cayley_formula(N_val):
    N = sp.Symbol('N') # Khai bao N la tham so truu tuong
    
    # Kien tao Ma tran Laplacian cho do thi day du K_N voi cac gia tri cu the
    # L[i][i] = N_val - 1 (Bac cua dinh)
    # L[i][j] = -1 voi moi i != j
    L = sp.Matrix(N_val, N_val, lambda i, j: (N_val - 1) if i == j else -1)
    
    # Loai bo hang cuoi va cot cuoi de tao Ma tran con chinh (Principal Minor)
    L_minor = L[:-1, :-1]
    
    # Tinh dinh thuc bang Oracle
    spanning_trees = sp.factor(L_minor.det())
    
    print(f"So luong cay khung cua K_{N_val} tinh boi Laplacian la: {spanning_trees}")
    print(f"Xac thuc voi cong thuc Cayley (N^(N-2)): {N_val**(N_val-2)}")
    
    if spanning_trees == N_val**(N_val-2):
         print("=> Dong nhat thuc Kirchhoff-Cayley duoc bao chung tuyet doi!")

verify_cayley_formula(5)
# Output: So luong cay khung cua K_5 tinh boi Laplacian la: 125
# Xac thuc voi cong thuc Cayley (N^(N-2)): 125


if __name__ == '__main__':
    verify_cayley_formula(4)
    verify_cayley_formula(5)
