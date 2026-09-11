import scipy.optimize as opt


def find_rolle_point(f, a, b):
    res = opt.minimize_scalar(lambda x: abs(
        opt.approx_fprime(x, f)), bounds=(a, b), method='bounded')
    return res.x
