import numpy as np


def find_all_complex_roots(coefficients):
    # Tim tat ca cac nghiem cua da thuc dua tren ma tran dong hanh (companion
    # matrix)
    return np.roots(coefficients)
