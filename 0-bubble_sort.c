#include <stdbool.h>
#include <stddef.h> // for size_t
#include "sort.h"

void bubble_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < size; i++) {
            if (array[i-1] > array[i]) {
                int tmp = array[i-1];
                array[i-1] = array[i];
                array[i] = tmp;
                swapped = true;
                print_array(array, size);
            }
        }
        size--;
    } while (swapped);
}

