/*
    Search an element in sorted and pivoted array
    Ex: [3,4,5,1,2]
    Source: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
    Time complexity: O(log n)
    Space complexity: O(1)
*/

#include<iostream>
using namespace std;

void searchAnElement(int array[], int target, int low, int high) {
    if (low > high) {
        cout << "Couldn't find the element" << endl;
        return;
    }

    int mid = (low + high) / 2;
    if (target == array[mid]) {
        cout << "Element found at index: " << mid << endl;
        return;
    } else if (target < array[mid]) {
        if (target > array[low]) {
            high = mid - 1;
        } else if (target < array[low]) {
            low = mid + 1;
        }
        searchAnElement(array, target, low, high);
    } else if (target > array[mid]) {
        low = mid + 1;
        searchAnElement(array, target, low, high);
    }
}

int main() {
    int array[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int arraySize = sizeof(array) / sizeof(array[0]);
    int target = 10;
    searchAnElement(array, target, 0, arraySize - 1);
}