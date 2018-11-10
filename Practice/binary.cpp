#include <iostream>

int binarySearch(int arr[], int left, int right,int target) {
    int mid = (left + right) / 2;

    if (arr[mid] == target) {
	return mid;
    }
    else if (arr[mid] > target) {
	right = mid - 1;
	return binarySearch(arr, left, right, target);
    }
    else {
	left = mid + 1;
	return binarySearch(arr, left, right, target);
    }
    
    return -1;
}

int evenBinarySearch(int arr[],int left, int right) {
    int mid = (left + right) / 2;

    if (arr[mid] % 2 == 1 && arr[mid - 1] % 2 == 0) {
	return mid;
    }
    else if (arr[mid] % 2 == 0) {
	left = mid + 1;
	return evenBinarySearch(arr,left,right);
    }
    else {
	right = mid - 1;
	return evenBinarySearch(arr, left, right);
    }

    return -1;
}



int main(int argc, char *argv[]) {
    int arr[7] = {1,2,3,4,5,6,7};
    int evenarr[7] = {2,4,6,8,6,3,5};

    // normal binary search
    
    std::cout << binarySearch(arr, 0, 6, 2) << "\n";
    std::cout << binarySearch(arr, 0, 6, 4) << "\n";
    std::cout << binarySearch(arr, 0, 6, 1) << "\n";
    std::cout << binarySearch(arr, 0, 6, 7) << "\n";

    // even coding interview binary search

    std::cout << evenBinarySearch(evenarr, 0, 6) << "\n";
    
    
    return 0;
}
