#include <stdio.h>

#define d 10

int main() {
    double A[d] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double B[d] = {11.0, -12.0, 13.0, 14.0, -15.0};
    double C[d] = {0.0, 0.0, 0.0, 0.0, 0.0};
    
    
    double real = A[0];
    for (int i = 1; i < d; i++) {
        if (A[i] > real) {
            real = A[1];
        }
    }
    int otric = 0;
    for (int i = 0; i < d; i++) {
        if (B[i] < 0) {
            otric++;
        }
    }

    for (int i = 0; i < d; i++) {
        C[i] += A[i] + B[i];
    }
    double s = 0;
    for (int i = 0; i < d; i++) {
        s += C[i];
    }

    double avg = s / (2 * d);

    printf("Макс %.2lf\n", real);
    printf("Мнимое %d\n", otric);
    printf("Среднее %.2lf\n", avg); 

    return 0;
}
