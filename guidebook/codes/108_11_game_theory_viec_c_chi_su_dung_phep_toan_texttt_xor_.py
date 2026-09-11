import functools


def mex(subset):
    mex_val = 0
    while mex_val in subset:
        mex_val += 1
    return mex_val


@functools.lru_cache(maxsize=None)
def calculate_grundy(n):
    if n == 0:
        return 0
    moves = [1, 2, 3]
    next_states = set()
    for m in moves:
        if n >= m:
            next_states.add(calculate_grundy(n - m))
    return mex(next_states)


game_states = [4, 5, 6]
oracle_nim_sum = 0
for state in game_states:
    oracle_nim_sum ^= calculate_grundy(state)

algebraic_nim_sum = (4 % 4) ^ (5 % 4) ^ (6 % 4)

print(f"Output: Objective state via Graph MEX computation: {oracle_nim_sum}")
print(f"Output: Objective state via Algebraic XOR convolution: {algebraic_nim_sum}")
assert oracle_nim_sum == algebraic_nim_sum
