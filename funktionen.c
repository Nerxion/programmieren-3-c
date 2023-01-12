#include <stdio.h>

double f1(double x);
double f2(double x);
double f3(double x);

double regula(double x1, double x2, double (*f)(double)) {
    double xs = 0, betragVonfxs = 0;
    if ((f(x1) * f(x2)) > 0) return 0; /* eig >= 0 */

    xs = x1 - f(x1) * ((x2 - x1) / (f(x2) - f(x1)));
    if (f(xs) < 0) betragVonfxs = f(xs) * -1;
    else betragVonfxs = f(xs);
    while (betragVonfxs >= 1E-6) {
        if ((f(xs) < 0 && f(x1) < 0) || (f(xs) > 0 && f(x1) > 0)) {
            xs = xs - f(xs) * ((x2 - xs) / (f(x2) - f(xs)));
        }
        else {
            xs = x1 - f(x1) * ((xs - x1) / (f(xs) - f(x1)));
        }
        if (f(xs) < 0) betragVonfxs = f(xs) * -1;
        else betragVonfxs = f(xs);
    }
    
    return xs;
}

double f1(double x) {
    int y = 0;
    y = (x * x) - 9; /* x^2 - 9, Nullstelle bei x=3 */
    return y;
}

double f2(double x) {
    int y = 0;
    y = (x * x) - 3; /* x^2 - 3, Nullstelle bei x=1.732 */
    return y;
}

double f3(double x) {
    int y = 0;
    y = x + 2; /* x + 2, Nullstelle bei x=-2 */
    return y;
}

int main(void) {
    double x1 = 0, x2 = 0, ergebnis = 0;

    while (x1 == x2) {
        printf("Intervallanfang eingeben: \n");
        scanf("%lf", &x1);
        printf("Intervallende eingeben: \n");
        scanf("%lf", &x2);
    }

    ergebnis = regula(x1, x2, f1);

    if (ergebnis == 0) printf("Nope nope, oder sollte die Nullstelle bei 0 sein? \n");
    else printf("Nullstelle: %g\n", ergebnis);

    return 0;
}