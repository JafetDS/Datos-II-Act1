#include <iostream>
#include "virtualMemo.h"
/**
 * @brief function that recieves an array, and places the first element 
 * in its expected position, and then places all lower elements to its
 * left, and bigger elements to its rigth, then returns the index of the
 * element used as pivot
 * 
 * @param arr array to sort
 * @param start index where the subarray starts
 * @param end index where the subarray ends
 * @return index of the element to be used as pivot
 */
int partition(virtualMemo* arr, int start, int end) {
    int pivot = arr->get(start);
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr->get(i) <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    arr->swap(pivotIndex,start);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
        while (arr->get(i) <= pivot) {
            i++;
        }
        while (arr->get(j) > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            arr->swap(i++, j--);
        }
    }
    return pivotIndex;
}

/**
 * @brief algorithm that sorts an array by didiving it in two
 * subarrays with smaller and bigger values of a pivot element
 * 
 * @param arr array to sort
 * @param start point to start sorting from
 * @param end point to stop sorting
 */
void quickSort(virtualMemo* arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}