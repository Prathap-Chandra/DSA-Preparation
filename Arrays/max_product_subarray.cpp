/*
    Find a contiguous non-empty subarray within the array
    that has the largest product.
    Time complexity: O(n)
*/

#include <iostream>
using namespace std;

int maxProductSubArray(int array[], int arraySize)
{
    int maxProductEndingHere = 1;
    int minProductEndingHere = 1;
    int maxProductSoFar = array[0];
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == 0) {
            maxProductEndingHere = 1;
            minProductEndingHere = 1;
            maxProductSoFar = 0;
            continue;
        }
        
        int temp = maxProductEndingHere * array[i];
        maxProductEndingHere = max(
            maxProductEndingHere * array[i],
            minProductEndingHere * array[i]
        );
        maxProductEndingHere = max(maxProductEndingHere, array[i]);
        minProductEndingHere = min(
            minProductEndingHere * array[i],
            array[i]
        );
        minProductEndingHere = min(minProductEndingHere, temp);

        maxProductSoFar = max(maxProductSoFar, maxProductEndingHere);
    }
    return maxProductSoFar;
};

int main()
{
    // int array[] = {-2, -3, 0, -2, -40};
    // int array[] = {6, 3, -10, 0, 2};
    // int array[] = {-6, 0, -3, 0, -1, 0, -2};
    int array[] = {-2, 0, -1};
    // int array[] = {-1,-2,-9,-6};
    int arraySize = sizeof(array) / sizeof(array[0]);
    cout << "Maximum Product Subarray: " << maxProductSubArray(array, arraySize) << endl;
}