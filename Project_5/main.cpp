#include "SortingTests.hpp"

// test function for printing arrays 
void printArray(int arr[], size_t size) {
    for (int i = 0; i < size; ++i) 
        std::cout << " " << arr[i];
}


int main(int argc, char *argv[]) {

    // for testing 
    int arr[20];
    
    int size2 = 20;

    // generateRandomArray(arr,size2);
    // generateDescendingArray(arr,size2);
    // printArray(arr, size2);
    
    // mergesort
    std::cout << sortTest(&insertionSort, arr, size2) << "\n"; 
    
    // selection sort
    /*    selectionSort(test, size);
    printArray(test, size);

    // insertion sort
    insertionSort(test, size);
    printArray(test, size);
    */ 
    return 0;
}
