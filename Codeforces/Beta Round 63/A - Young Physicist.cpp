#include <stdio.h>
int main() {
    int n, x, y, z;
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        a = a + x;
        b = b + y;
        c = c + z;
    }
    if (a == 0 && b == 0 && c == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
