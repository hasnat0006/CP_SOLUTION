#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[]) {
    char str[105];
    gets(str);
    int l, a = 0, b = 0, c = 0;
    l = strlen(str);
    for (int i = 0; i < l; i++) {
        if (str[i] == '1') {
            a++;
        }
        else if (str[i] == '2') {
            b++;
        }
        else if (str[i] == '3') {
            c++;
        }
    }
    int n = a + b + c;
    //    printf("%d",n);
    int b1 = a + b;
    for (int i = 1; i <= n; i++) {
        if (i <= a) {
            if (i == n) {
                printf("1");
            }
            else {
                printf("1+");
            }
        }
        else if (i <= b1 && i > a) {
            if (i == n) {
                printf("2");
            }
            else {
                printf("2+");
            }
        }
        else {
            if (i == n) {
                printf("3");
            }
            else {
                printf("3+");
            }
        }
    }

    return 0;
}
