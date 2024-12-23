#include <stdio.h>

void main() {

        int a;
        printf("введите год: ");
        scanf("%d",&a);
        if (a % 400 == 0)
                printf("вискосный");
        else if (a % 100 == 0)
                printf("не високосный");
        else if (a % 4 == 0)
                printf("високосный");
        else
                printf("не високосный");
}
