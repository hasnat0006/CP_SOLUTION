#include <math.h>
#include <stdio.h>
#include <string.h>
#define int long long
#include <stdlib.h>
int sorting(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int main() {
    int s, n;
    scanf("%lld%lld", &s, &n);
    int str[n], bonus[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &str[i], &bonus[i]);
    }
    int f = 0;
    // qsort(str,n,sizeof(int),sorting);
    // qsort(bonus,n,sizeof(int),sorting);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                int temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
                int temp1 = bonus[j];
                bonus[j] = bonus[j + 1];
                bonus[j + 1] = temp1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s > str[i]) {
            s = s + bonus[i];
            f = 1;
        }
        else {
            f = 0;
            break;
        }
    }
    if (f == 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}