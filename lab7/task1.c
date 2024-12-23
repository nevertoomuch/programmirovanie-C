#include <stdio.h>

int main() {
    int prob = 0;
    int j = 0;
    char result[100];
    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,    sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";  

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' '){
            result[j] = str[i];
            j++;
        }else{
            prob++;
        }
    
    }
    result[j] = '\0';

    printf("Пробелов: %d\n", prob);
    printf("Итог: %s", result);


    return 0;
}
