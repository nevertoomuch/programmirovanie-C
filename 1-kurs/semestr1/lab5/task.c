#include <stdio.h>
unsigned int x(unsigned int a, int k) {
    return (a >> k) | (a << (32 - k));
}

int main() {
    unsigned int a = 0xF1234567;  // возьмем пример числа
    int k = 4;  // кол-во сдвигов для этого числа

    unsigned int result = x(a, k);
    printf("result: 0x%X\n", result);

    return 0;
}
