/*
    Source: https://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/
    Given an array of integers which is initially increasing and then decreasing, 
    find the maximum value in the array. 
    Time complexity: O(log n)
    Space complexity: O(1)
*/

#include<iostream>
using namespace std;

void searchForMaxElement(int array[], int low, int high) {
    if (low > high) {
        cout << "Couldn't find the element" << endl;
        return;
    }

    if (high == low) {
        cout << "Max element is: " << array[low] << endl;
        return;
    }

    int mid = (low + high) / 2;
    if (array[mid] > array[mid - 1] && array[mid] > array[mid + 1]) {
        cout << "Max element is: " << array[mid] << endl;
        return;
    } else if (array[mid] > array[mid - 1] && array[mid] < array[mid + 1]) {
        low = mid + 1;
        searchForMaxElement(array, low, high);
    } else if (array[mid] < array[mid - 1] && array[mid] > array[mid + 1]) {
        high = mid - 1;
        searchForMaxElement(array, low, high);
    }   
}

int main() {
    int array[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int arraySize = sizeof(array) / sizeof(array[0]);
    searchForMaxElement(array, 0, arraySize - 1);
}