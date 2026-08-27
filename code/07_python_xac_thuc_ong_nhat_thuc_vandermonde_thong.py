import sympy as sp

def verify_vandermonde(n):
    # Khoi tao tap cac bien ky hieu (symbolic variables)
    x = sp.symbols(f'x1:{n+1}')
    
    # Kien tao ma tran Vandermonde V_n
    V = sp.Matrix(n, n, lambda i, j: x[i]**j)
    
    # Tinh dinh thuc va phan tich cau truc nhan tu
    det_V = sp.factor(V.det())
    
    print(f"Dinh thuc Vandermonde cap {n}:")
    print(det_V)

# Kiem chung the nghiem (Empirical verification) voi n = 4
verify_vandermonde(4)
# Output: (x1 - x2)*(x1 - x3)*(x1 - x4)*(x2 - x3)*(x2 - x4)*(x3 - x4)


if __name__ == '__main__':
    verify_vandermonde(4)
    verify_vandermonde(5)
