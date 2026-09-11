import scipy.optimize as opt


def numeric_root_approximation(f, x0):
    # Truc tiep tiem can nghiem so do rao can Galois
    return opt.newton(f, x0)
