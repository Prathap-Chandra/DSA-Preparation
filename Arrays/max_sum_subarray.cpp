/*
    Find a contiguous non-empty subarray within the array
    that has the largest product.
    Time complexity: O(n)
*/

#include <iostream>
using namespace std;

int maxSumSubArray(int array[], int arraySize)
{
    int maxSumEndingHere = array[0];
    int maxSumSoFar = array[0];
    for (int i = 1; i < arraySize; i++)
    {
        maxSumEndingHere = max(maxSumEndingHere + array[i], array[i]);
        if (maxSumSoFar < maxSumEndingHere) {
            maxSumSoFar = maxSumEndingHere;
        }
    }
    return maxSumSoFar;
};

int main()
{
    int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arraySize = sizeof(array) / sizeof(array[0]);
    cout << "Maximum Sum Subarray: " << maxSumSubArray(array, arraySize);
}