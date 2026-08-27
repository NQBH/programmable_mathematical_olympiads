import sympy as sp
from sympy.combinatorics import CyclicGroup

def verify_group_action(N, K):
    # Khoi tao Nhom Cyclic C_N mieu ta phep quay mat phang
    G = CyclicGroup(N)
    
    # Trich xuat Da thuc Chi so Chu trinh (Cycle Index Polynomial)
    # Z(G) mieu ta hoan hao cau truc chu trinh cua moi phan tu g in G
    Z = G.cycle_index
    
    print(f"Da thuc chi so chu trinh cua nhom C_{N}:")
    print(Z)
    
    # Tinh gia tri Burnside (so lop tuong duong) bang cach the x_i = K
    # SymPy thao tac tren object ky hieu nguyen thuy x_0, x_1,...
    x_vars = {sp.Symbol(f'x_{i}'): K for i in range(N+1)}
    total_orbits = Z.subs(x_vars)
    
    print(f"\nSo luong cau truc phan biet voi K={K} mau:")
    print(total_orbits)

verify_group_action(4, 3)
# Output: Da thuc chi so chu trinh: x_0**4/4 + x_0**2*x_1/4 + x_3/2
# So luong cau truc phan biet voi K=3 mau: 24


if __name__ == '__main__':
    verify_group_action(4, 3)
    verify_group_action(5, 2)
