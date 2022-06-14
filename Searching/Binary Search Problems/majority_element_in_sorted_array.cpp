/*
    if a given integer x appears more than n/2 times in a sorted array of n integers. 
    Basically, we need to write a function say isMajority() that takes 
    an array (arr[] ), array’s size (n) and a number to be searched (x) as parameters 
    and returns true if x is a majority element (present more than n/2 times).

    Time complexity: O(log n)
    Space complexity: O(1)
*/ 

#include<iostream>
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

int main() {
    int array[] = {1, 2, 3, 3, 3, 3, 10};
    int arraySize = sizeof(array) / sizeof(array[0]);
    int target = 5;
    int leftMostIndex = -1;
    int rightMostIndex = -1;
    getLeftMostIndex(array, target, 0, arraySize, leftMostIndex);
    getRightMostIndex(array, target, 0, arraySize, rightMostIndex);
    if (leftMostIndex == -1 || rightMostIndex == -1) {
        cout << "Couldn't find " << target << " in the array" << endl;
        return 0;
    }

    int frequency = rightMostIndex - leftMostIndex + 1;
    if (frequency >= arraySize/2) {
        cout << target << " is a majority element" << endl;
    } else {
        cout << target << " is not a majority element" << endl;
    }
}