#include <stdio.h>

int main() {
    int a;
    printf("chislo?");
    scanf("%d", &a);
    if (a < 2) {
        puts("0");
        return 0;
    }
    int n = 2;
    for(n = 2; n < a && a % n != 0; n ++);
    if (n == a)
            puts("1");
    else
            puts("0");
    return 0;
}
