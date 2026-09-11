def check_monotone_convergence(seq, epsilon=1e-7):
    for i in range(1, len(seq)):
        if seq[i] < seq[i - 1]:
            return False
    return (seq[-1] - seq[-2]) < epsilon
