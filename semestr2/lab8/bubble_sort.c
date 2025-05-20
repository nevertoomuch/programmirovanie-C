#include <stddef.h>   
#include "bubble_sort.h"

void bubble_sort(int arr[], int n) {
    if (arr == NULL || n <= 1) {
        return;
    }

    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
