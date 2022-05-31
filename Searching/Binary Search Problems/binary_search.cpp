/*
    Binary Search
    Time complexity: O(log n)
    Space complexity: O(1)
*/ 

#include<iostream>
using namespace std;

void binarySearch(int array[], int arraySize, int elementToSearch, int low, int high) {

    if (low > high) {
        cout << "\nElement not found" << endl;
        return;
    }

    int mid = (low + high) / 2;
    if (elementToSearch == array[mid]) {
        cout << "\nElement found at index: " << mid << endl;
    } else if (elementToSearch > array[mid]) {
        low = mid + 1;
        binarySearch(array, arraySize, elementToSearch, low, high);
    } else if (elementToSearch < array[mid]) {
        high = mid - 1;
        binarySearch(array, arraySize, elementToSearch, low, high);
    }
}

int main() {
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int arraySize = sizeof(array)/sizeof(array[0]);
    int elementToSearch;
    cout << "\nEnter an element to search in the array: ";
    cin >> elementToSearch;

    binarySearch(array, arraySize, elementToSearch, 0, arraySize - 1);
}