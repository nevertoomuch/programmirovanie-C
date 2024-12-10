#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main() {
    int n;
    printf("Введите количество точек: ");
    scanf("%d", &n);

    Point *points = (Point *)malloc(n * sizeof(Point));
    if (points == NULL) {
        fprintf(stderr, "Ошибка выделения памяти!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Введите координаты точки %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    for (int i = 0; i < n; i++) {
        printQuadrant(points[i]);
    }

    free(points);
    return 0;
}
