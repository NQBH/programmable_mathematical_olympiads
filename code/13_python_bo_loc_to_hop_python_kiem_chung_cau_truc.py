import itertools

def count_n_queens_python(n):
    # Khong gian hoan vi dam bao invariant hang va cot
    permutations = itertools.permutations(range(n))
    valid_configs = 0
    
    for perm in permutations:
        # Kiem tra cac bat bien tren duong cheo (r-c va r+c)
        diag1 = len(set(r - c for r, c in enumerate(perm)))
        diag2 = len(set(r + c for r, c in enumerate(perm)))
        
        # Neu so luong duong cheo bang dung N, khong co su va cham
        if diag1 == n and diag2 == n:
            valid_configs += 1
            
    return valid_configs

# Kiem chung song anh giua ket qua Toan hoc va Thuat toan Bitwise
N = 8
print(f"So luong cau hinh hop le cho N={N} la: {count_n_queens_python(N)}")
# Output: 92


if __name__ == '__main__':
    for n in range(4, 9):
        print(f"So luong cau hinh hop le cho N={n} la: {count_n_queens_python(n)}")
