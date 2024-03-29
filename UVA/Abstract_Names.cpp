#include <math.h>
#include <stdio.h>
#include <string.h>
int main() {
    int n, i, j;
    scanf("%d", &n);
    getchar();
    char str1[25];
    char str2[25];
    for (i = 0; i < n; i++) {
        gets(str1);
        gets(str2);
        int l1 = strlen(str1);
        int l2 = strlen(str2);
        if (l1 == l2) {
            int f = 0, c = 0;
            for (j = 0; j < l1; j++) {
                if (str1[j] == 'a' || str1[j] == 'e' || str1[j] == 'i' ||
                    str1[j] == 'o' || str1[j] == 'u') {
                    if (str2[j] == 'a' || str2[j] == 'e' || str2[j] == 'i' ||
                        str2[j] == 'o' || str2[j] == 'u') {
                        f = 0;
                    }
                    else {
                        f++;
                    }
                }
                else if (str1[j] != str2[j]) {
                    c = 1;
                }
            }
            if (c == 1) {
                printf("No\n");
            }
            else if (f > 0) {
                printf("No\n");
            }
            else {
                printf("Yes\n");
            }
        }
        else
            printf("No\n");
    }

    return 0;
}