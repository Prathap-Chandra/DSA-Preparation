/* 
    Given an array of integers containing only 0's, 1's and 2's. Sort them.
    Time Complexity: O(n)
    Space Complexity: O(1)
*/ 

#include<iostream>
using namespace std;

int main() {
    int array[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arraySize = sizeof(array)/sizeof(array[0]);
    int low = 0;
    int mid = 0;
    int high = arraySize - 1;
    cout << "low: " << low << endl;
    cout << "mid: " << mid << endl;
    cout << "high: " << high << endl;

    while (mid <= high)
    {
        switch (array[mid])
        {
        case 0:
            swap(array[low], array[mid]);
            low++;
            mid++;
            break;

        case 1:
            mid++;
            break;
        
        case 2:
            swap(array[mid], array[high]);
            high--;
            break;  
        
        default:
            break;
        }
    }

    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }
    
}