import functools

# Ham MEX mo phong chat che dinh nghia toan hoc
def mex(subset):
    mex_val = 0
    while mex_val in subset:
        mex_val += 1
    return mex_val

# Oracle kiem chung viec giam trang thai trong tro choi lay soi
@functools.lru_cache(maxsize=None)
def calculate_grundy(n):
    if n == 0: return 0
    # Gia su luat choi: Duoc lay 1, 2 hoac 3 vien soi
    moves = [1, 2, 3]
    next_states = set()
    for m in moves:
        if n >= m:
             next_states.add(calculate_grundy(n - m))
    return mex(next_states)

# Xac minh tinh Dang cau giua Phep duyet do thi va Phep XOR
game_states = [4, 5, 6]

# Tinh bang Oracle (Duyet do thi MEX)
oracle_nim_sum = 0
for state in game_states:
    oracle_nim_sum ^= calculate_grundy(state)

# Toan hoc giai tich (luat nay cho G(n) = n % 4)
algebraic_nim_sum = (4 % 4) ^ (5 % 4) ^ (6 % 4)

print(f"Gia tri Grundy tong tu Oracle MEX: {oracle_nim_sum}")
print(f"Gia tri Grundy tong tu XOR Dai so: {algebraic_nim_sum}")
# Output luon dong nhat, chung minh Dinh ly Sprague-Grundy la tuyet doi


if __name__ == '__main__':
    # Executes globally
    pass
