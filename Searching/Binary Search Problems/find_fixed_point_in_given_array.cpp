/*
    Given an array of n distinct integers sorted in ascending order,
    write a function that returns a Fixed Point in the array,
    if there is any Fixed Point present in array, else returns -1.
    Fixed Point in an array is an index i such that arr[i] is equal to i.
    Note that integers in array can be negative.
*/

#include <iostream>
using namespace std;

void fixedPoint(int array[], int low, int high) {
    if (low > high) {
        cout << "Couldn't find a fixed point in the array";
        return;
    }

    int mid = (low + high) / 2;
    if (mid == array[mid]) {
        cout << "Element " << array[mid] << " found at index " << mid << endl;
        return;
    } else if ((array[mid] < 0) || (mid > array[mid])) {
        low = mid + 1;
        fixedPoint(array, low, high);
    } else if (mid < array[mid]) {
        high = mid - 1;
        fixedPoint(array, low, high);
    }
}

int main()
{
    int array[] = {-1, 0, 1, 2, 3, 6};
    int arraySize = sizeof(array) / sizeof(array[0]);
    fixedPoint(array, 0, arraySize - 1);
}