#include <iostream>
#include  "virtualMemo.h"
/**
 * @brief algorithm to sort an array by checking two elements
 * next to each other and swaping them if necesary, repeating 
 * until no more swaps are necesary
 * 
 * @param arr array to sort
 * @param n length of the array
 */
void bubbleSort(virtualMemo* arr, int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr->get(j) > arr->get(j + 1)) {
                arr->swap(j, j + 1);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}