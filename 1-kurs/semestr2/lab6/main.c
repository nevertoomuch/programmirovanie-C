#include <stdio.h>
#include "person.h"
#include "search.h"

int main() {
    const char* filename = "Znak.dat";
    int N;

    printf("Сколько записей вы хотите создать? ");
    scanf("%d", &N);

    createFile(filename, N);
    searchFile(filename);

    return 0;
}
