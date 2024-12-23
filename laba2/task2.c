#include <stdio.h>

void main(){
        float chislo;
        char temp;
        printf("temperatura: ");
        scanf ("%f",&chislo);
        scanf ("%c",&temp);
        if (temp == 'f')
                printf("%f\n", (chislo - 32) / 1.8);
        else if (temp == 'c' )
                printf("%f\n",chislo* 1.8 + 32);
        else
                printf("oshibka");
            
}
