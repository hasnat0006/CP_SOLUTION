#include <math.h>
#include <stdio.h>
#include <string.h>
int main() {
    int t, x, y;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        x = log2(n);
        y = pow(2, x);
        printf("%d\n", y - 1);
    }
    return 0;
}