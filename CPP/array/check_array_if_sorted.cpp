/*Problem Statement

Input: [1, 2, 3, 5, 4] → Output: Not Sorted

Input: [1, 2, 3, 4, 5] → Output: Sorted

Pattern

Array – Adjacent Comparison / Single Scan

We traverse the array once, comparing each element with its next neighbor.

If any element > next element, the array is not sorted.

Otherwise, it’s sorted.

Algorithm

Traverse the array from index 0 to n-2.

For each i, check if arr[i] > arr[i+1].

If yes → array is not sorted, stop.

If loop finishes → array is sorted. */
















#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 5, 4};        // input array
    int n = sizeof(arr)/sizeof(arr[0]); // size of array
    bool sorted = true;                  // assume array is sorted

    for(int i = 0; i < n - 1; i++) {    // traverse array till second last element
        if(arr[i] > arr[i+1]) {         // compare current element with next
            sorted = false;             // not sorted
            break;                      // no need to check further
        }
    }

    if(sorted)                          // check flag
        cout << "Sorted\n";
    else
        cout << "Not Sorted\n";

    return 0;
}
