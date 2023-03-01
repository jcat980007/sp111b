#include <stdio.h>
#include <stdarg.h>

double integrate(double (*f)(double), double a, double b, int n, ...) {
    double dx = (b - a) / n;
    double sum = 0.0;
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        double x = a + i * dx;
        double fx = (*f)(x);
        sum += fx * va_arg(args, double);
    }
    va_end(args);
    return sum * dx;
}

double square(double x) {
    return x*x;
}

int main() {
    printf("integrate(square, 0.0, 2.0, 100, 1.0, 4.0, 1.0, 4.0, ... )=%f\n", integrate(square, 0.0, 2.0, 100, 1.0, 4.0, 1.0, 4.0));
}