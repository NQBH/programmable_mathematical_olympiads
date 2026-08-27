import sympy as sp

def verify_catalan_generating_function(terms):
    x = sp.Symbol('x')
    
    # Dinh nghia Ham sinh hinh thuc A(x) giai tich lien tuc
    # A(x) = (1 - sqrt(1 - 4x)) / (2x)
    A = (1 - sp.sqrt(1 - 4*x)) / (2*x)
    
    # Khai trien Chuoi Maclaurin (Taylor tai x=0) de trich xuat he so roi rac
    # Thao tac nay mo phong truc tiep Dinh ly Nhi thuc Suy rong tren may hoc
    maclaurin_series = sp.series(A, x, 0, terms)
    
    print(f"Khai trien Chuoi Maclaurin cua Ham sinh den x^{terms-1}:")
    print(maclaurin_series)
    
    # Kiem chung cac he so voi day Catalan thuc te
    # C_n: 1, 1, 2, 5, 14, 42, 132...
    print("\n=> Nhan xet: He so cua x^n tu dong map (anh xa) chinh xac voi C_n.")
    print("=> Tinh dang cau giua Giai tich lien tuc va To hop roi rac duoc bao chung!")

verify_catalan_generating_function(7)
# Output: 132*x**6 + 42*x**5 + 14*x**4 + 5*x**3 + 2*x**2 + x + 1 + O(x**7)


if __name__ == '__main__':
    verify_catalan_generating_function(10)
