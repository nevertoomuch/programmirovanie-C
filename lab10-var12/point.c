#include <stdio.h>
#include "point.h"

void printQuadrant(Point p) {
    if (p.x > 0 && p.y > 0) {
        printf("Точка (%.2lf, %.2lf) расположена в первом координатном угле.\n", p.x, p.y);
    } else if (p.x < 0 && p.y > 0) {
        printf("Точка (%.2lf, %.2lf) расположена во втором координатном угле.\n", p.x, p.y);
    } else if (p.x < 0 && p.y < 0) {
        printf("Точка (%.2lf, %.2lf) расположена в третьем координатном угле.\n", p.x, p.y);
    } else if (p.x > 0 && p.y < 0) {
        printf("Точка (%.2lf, %.2lf) расположена в четвертом координатном угле.\n", p.x, p.y);
    } else if (p.x == 0 && p.y == 0) {
        printf("Точка (%.2lf, %.2lf) расположена в начале координат.\n", p.x, p.y);
    } else if (p.x == 0) {
        printf("Точка (%.2lf, %.2lf) расположена на оси Y.\n", p.x, p.y);
    } else {
        printf("Точка (%.2lf, %.2lf) расположена на оси X.\n", p.x, p.y);
    }
}
