/*
    Given an array of sorted integers find the frequency of a given number.
    Time complexity: O(log n)
    Space complexity: O(n)
*/

#include <iostream>
using namespace std;

void getLeftMostIndex(int array[], int target, int low, int high, int &leftMostIndex) {
    if (low > high) {
        return;
    }

    int mid = (low + high) / 2;
    if (target == array[mid]) {
        leftMostIndex = mid;
        high = mid - 1;
        getLeftMostIndex(array, target, low, high, leftMostIndex);
    } else if (target > array[mid]) {
        low = mid + 1;
        getLeftMostIndex(array, target, low, high, leftMostIndex);
    } else if (target < array[mid]) {
        high = mid - 1;
        getLeftMostIndex(array, target, low, high, leftMostIndex);
    }
}

void getRightMostIndex(int array[], int target, int low, int high, int &rightMostIndex) {
    if (low > high) {
        return;
    }

    int mid = (low + high) / 2;
    if (target == array[mid]) {
        rightMostIndex = mid;
        low = mid + 1;
        getRightMostIndex(array, target, low, high, rightMostIndex);
    } else if (target > array[mid]) {
        low = mid + 1;
        getRightMostIndex(array, target, low, high, rightMostIndex);
    } else if (target < array[mid]) {
        high = mid - 1;
        getRightMostIndex(array, target, low, high, rightMostIndex);
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 6, 7, 8, 9, 10};
    int target = 5;
    int arraySize = sizeof(array) / sizeof(array[0]);
    int leftMostIndex = -1;
    int rightMostIndex = -1;
    getLeftMostIndex(array, target, 0, arraySize - 1, leftMostIndex);
    getRightMostIndex(array, target, 0, arraySize - 1, rightMostIndex);
    if (leftMostIndex != -1 && rightMostIndex != -1) {
        cout << "Frequency of number is: " << rightMostIndex - leftMostIndex + 1 << endl;
    } else {
        cout << "Couldn't find the element" << endl;
    }
}