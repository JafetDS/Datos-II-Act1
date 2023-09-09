#include <iostream>
#include "virtualMemo.h"

/**
 * @brief algorithm to sort an array by finding the minimum element
 * and moving it to the first position, then repeating this for each
 * position
 * 
 * @param arr array to sort
 * @param n length of the array
 */
void selectionSort(virtualMemo* arr, int n){
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr->get(j) < arr->get(min_idx))
                min_idx = j;
        }
        if (min_idx != i) {
            arr->swap(min_idx, i);
        }
    }
}