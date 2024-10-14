#include <math.h>
#include <stdio.h>
#include <string.h>
void find() {
    char str[110];
    int f = 0;
    gets(str);
    int l = strlen(str);
    if (l % 2 == 1)
        printf("NO\n");
    else {
        for (int i = 0; i < l / 2; i++) {
            if (str[i] != str[(l / 2) + i]) {
                f = 1;
                break;
            }
        }
        if (f == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
        find();
    return 0;
}