#include <math.h>
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    float v_area[n];
    float v_a[n];
    float v_b[n];
    float v_c[n];

    for (int i = 0; i < n; i++) {
        float a, b, c;
        scanf("%f %f %f", &a, &b, &c);
        float s = (a + b + c) / 2;
        float area = sqrt(s * (s - a) * (s - b) * (s - c));
        v_area[i] = area;
        v_a[i] = a;
        v_b[i] = b;
        v_c[i] = c;
    }

    // Sorting based on v_area
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v_area[j] > v_area[j + 1]) {
                float temp = v_area[j];
                v_area[j] = v_area[j + 1];
                v_area[j + 1] = temp;

                temp = v_a[j];
                v_a[j] = v_a[j + 1];
                v_a[j + 1] = temp;

                temp = v_b[j];
                v_b[j] = v_b[j + 1];
                v_b[j + 1] = temp;

                temp = v_c[j];
                v_c[j] = v_c[j + 1];
                v_c[j + 1] = temp;
            }
        }
    }

    // Printing sorted values
    for (int i = 0; i < n; i++) {
        printf("%.f %.f %.f\n", v_a[i], v_b[i], v_c[i]);
    }

    return 0;
}
