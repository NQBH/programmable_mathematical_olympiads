#include <iostream>

// Cauchy MVT evaluation for indeterminate limits (L'Hopital application)
double lhopital_eval(double (*df)(double), double (*dg)(double), double c) {
    return df(c) / dg(c);
}
