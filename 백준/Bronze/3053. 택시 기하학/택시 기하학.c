#include <stdio.h>
#define M_PI 3.14159265358979323846
#include <math.h>
int main() {
    double r, s1, s2;
    scanf("%lf", &r);
    s1 = r * r * M_PI;
    s2 = r * r * 2;
    printf("%.6lf\n%.6lf", s1, s2);
}