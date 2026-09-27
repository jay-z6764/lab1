#include <stdio.h>
#include <math.h>

int main() {
    float x0 = 1.0, x1 = 3.0;    
    float a0 = 2.0, a1 = 4.0;
    float hx = 1.3, ha = 1.3;

    for (float x = x0; x <= x1; x += hx) {
        for (float a = a0; a <= a1; a += ha)
{
            float o1 = -999999.0;
            if (x != 0 && (a - x) / x >= 0) {
                o1 = sqrt((a - x) / x);
            }

            float o2 = -999999.0;
            if (x != 0) {
                o2 = cos((a * a) / x);
            }

            float o3 = -999999.0;
            if (a >= 0) {
                float r = (x*x*x * sqrt(a)) / (a + 2.5);
                if (fabs(sin(r)) > 1e-6) {
                    o3 = cos(r) / sin(r);
                }
            }
            float z = o1;
            if (o2 > z) z = o2;
            if (o3 > z) z = o3;

            if (z == -999999.0) {
                 printf("x = %f; a = %f; z = ошибка\n", x, a);
            } else {
                 printf("x = %f; a = %f; z = %f\n", x, a, z);
            }
}
    }
return 0;
}
    
