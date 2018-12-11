// Assignment: CSCI 235, Fall 2018, Project 5
// Name: Marin Pavlinov Marinov
// Date: 11/08/18
// File Name: Sortingtests.cpp
// Implements sorting algoeithms

#include "SortingTests.hpp"

void selectionSort(int a[], size_t size) {
    int current_index = 0;

    while (current_index < size - 1) {
        
        int min = current_index;
        // transverse the array and find the index with the smallest number
        for (int i = current_index + 1; i < size; ++i) {
            if (a[i] < a[min])
                min = i;
        }

        // swap elements
        int hold = a[current_index];
        a[current_index] = a[min];
        a[min] = hold;
        
        // move index one over and start searching again 
        current_index++;
    }
}

void insertionSort(int a[], size_t size) {
    
    for (int i = 1; i < size; ++i) {
        // initialize min and prev_index 
        int curr = a[i];
        int prev_index = i - 1;

        // CHECK: if number is already sorted 
        if (curr < a[prev_index]) {
            // shift the numbers one index over until it is sorted 
            while (prev_index >= 0 && a[prev_index] > curr) {
                a[prev_index + 1] = a[prev_index];
                prev_index--;
            }
        }
        // place the number in the sorted position  
        a[prev_index + 1] = curr;
    }

}

void mergeSort(int a[], int from, int to) {
    if (from < to) {
        int mid = (from + to) / 2;

        // split two halves until there are only two elements 
        mergeSort(a,from, mid);
        mergeSort(a, mid + 1, to);

        //merging goes here
        mid = (from + to) / 2;
        
        // get size of arrays
        int leftSize = mid - from + 1;
        int rightSize = to - mid;

        // create arrays
        int L[leftSize];
        int R[rightSize];

        // fill arrays 
        for (int i = 0; i < leftSize; ++i) 
            L[i] = a[from + i];

        for (int j = 0; j < rightSize; ++j) 
            R[j] = a[mid + 1 + j];

        int leftIndex = 0;
        int rightIndex = 0;
        int mergedIndex = from;

        // merge two halves
        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (L[leftIndex] <= R[rightIndex]) {
                a[mergedIndex] = L[leftIndex];
                leftIndex++;
            }
            else {
                a[mergedIndex] = R[rightIndex];
                rightIndex++;
            }
            
            mergedIndex++;
        }

        // sort whatever is left
        while (leftIndex < leftSize) {
            a[mergedIndex] = L[leftIndex];
            leftIndex++;
            mergedIndex++;
        }

        while (rightIndex < rightSize) {
            a[mergedIndex] = R[rightIndex];
            rightIndex++;
            mergedIndex++;
        }
    } 
}

// creates an array of random integers 
void generateRandomArray(int values[], size_t size) {
    srand(static_cast<unsigned>(time(0)));

    values = new int[size];

    for (int i = 0; i < size; ++i)
        values[i] = (rand() % size) + 1; // avoid mode 0

}

// creates an array of random integers in ascending order
void generateAscendingArray(int values[], size_t size) {
    srand(static_cast<unsigned>(time(0)));
    int min = 1;

    values = new int[size];

    for (int i = 0; i < size; ++i) {
        values[i] = (rand() % 100 + min);
        min = values[i];
    }    
}

// generates array in descending order 
void generateDescendingArray(int values[], size_t size) {
    srand(static_cast<unsigned>(time(0)));
    int max = 100;

    values = new int[size];

    for (int i = 0; i < size; ++i) {
        values[i] = (rand() % max) + 1; // avoid mode 0 
        max = values[i];
    }
}

// generates an array in ascending order except the last 10 
void generateLastTenRandomArray(int values[], size_t size) {

    int last10_index = 0;
    // CHECK: make sure array is of size 10
    if (size >= 10) 
        last10_index = size - 10;
    else
        last10_index = size;


    int min = 1;

    values = new int[size];

    for (int i = 0; i < size; ++i) {
        if (i < last10_index) {
            values[i] = (rand() % 100) + min;
            min = values[i];
        }
        else {
            values[i] = (rand() % 100) + 1;
        }
    }

}

void generateFewRandomArray(int values[], size_t size) {
    srand(static_cast<unsigned>(time(0)));

    values = new int[size];

    for (int i = 0; i < size; ++i) 
        values[i] = (rand() % size) + 1; // avoid mod 0
}


// returns average amount of time of insertion and selection sort 
double sortTest(void (*sortingFunction)(int a[], size_t size), int values[], size_t size) {
    
    // start sum
    int run_time_sum = 0;
    
    // TEST 1
    generateRandomArray(values, size);
    
    auto start_time = high_resolution_clock::now();
    sortingFunction(values,size);
    auto end_time = high_resolution_clock::now();
    
    duration<double, std::micro> run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();
    
    // TEST 2
    generateAscendingArray(values, size);
    
    start_time = high_resolution_clock::now();
    sortingFunction(values,size);
    end_time = high_resolution_clock::now();

    run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();
    
    // TEST 3
    generateDescendingArray(values, size);
    
    start_time = high_resolution_clock::now();
    sortingFunction(values, size);
    end_time = high_resolution_clock::now();
    
    run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();

    // TEST 4
    generateFewRandomArray(values, size);
    
    start_time = high_resolution_clock::now();
    sortingFunction(values, size);
    end_time = high_resolution_clock::now();
    
    run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();
    
    // TEST 5
    generateLastTenRandomArray(values, size);
    
    start_time = high_resolution_clock::now();
    sortingFunction(values, size);
    end_time = high_resolution_clock::now();

    run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();
    
              
    return run_time_sum / 5;
}

// returns average amount of time for MergeSort to Sort 
double mergeSortTest(int values[], size_t size) {

    int run_time_sum = 0;
    
    // TEST 1
    generateRandomArray(values, size);

    auto start_time = high_resolution_clock::now();
    mergeSort(values,0, size - 1);
    auto end_time = high_resolution_clock::now();

    auto run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();

    // TEST 2
    generateAscendingArray(values, size);
    
    start_time = high_resolution_clock::now();
    mergeSort(values,0, size - 1);
    end_time = high_resolution_clock::now();

    run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();

    // TEST 3
    generateDescendingArray(values, size);

    start_time = high_resolution_clock::now();
    mergeSort(values,0, size - 1);
    end_time = high_resolution_clock::now();

    run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();

    
    // TEST 4
    generateFewRandomArray(values, size);

    start_time = high_resolution_clock::now();
    mergeSort(values,0, size - 1);
    end_time = high_resolution_clock::now();

    run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();


    // TEST 5
    generateLastTenRandomArray(values, size);
    
    start_time = high_resolution_clock::now();
    mergeSort(values,0, size - 1);
    end_time = high_resolution_clock::now();

    run_time = duration_cast<microseconds> (end_time - start_time);
    run_time_sum += run_time.count();

    

    return run_time_sum / 5;
}
