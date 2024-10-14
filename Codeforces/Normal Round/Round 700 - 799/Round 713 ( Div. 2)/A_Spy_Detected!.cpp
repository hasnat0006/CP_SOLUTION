#include <stdio.h>
int main(int argc, char const *argv[]) {
    int t, n, x, aa;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);
        int a[101] = {0};
        int fr[101] = {0};
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            fr[x] += 1;
            a[j] = x;
        }
        for (int j = 0; j < 101; j++) {
            if (fr[j] == 1) {
                aa = j;
            }
        }
        for (int j = 0; j < n; j++) {
            if (a[j] == aa) {
                printf("%d\n", j + 1);
            }
        }
    }
    return 0;
}
