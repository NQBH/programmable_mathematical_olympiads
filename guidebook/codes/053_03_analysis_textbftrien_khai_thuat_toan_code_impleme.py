import scipy.integrate as spi
import scipy.optimize as opt


def find_integral_mvt_point(f, g, a, b):
    If, _ = spi.quad(f, a, b)
    Ig, _ = spi.quad(g, a, b)
    res = opt.minimize_scalar(lambda c: abs(
        g(c) * If - f(c) * Ig), bounds=(a, b), method='bounded')
    return res.x
