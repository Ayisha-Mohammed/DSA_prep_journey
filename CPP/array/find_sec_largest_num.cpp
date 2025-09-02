/* 
Problem: Find the Second Largest Element in an Array
Step 1: Identify the Pattern

This problem falls under the “Array – Single Scan / Max-Min / Tracking Extremes” pattern:

Key points:

You need to track extremes (largest, second largest) while traversing.

Usually solved using two variables (first for largest, second for second largest).

Can be solved in two passes (find largest first, then second largest) or one pass (more optimal).

Pattern Name in Interviews:

“Tracking Max / Min while scanning an array”

Step 2: Understand Constraints

Array may have duplicates → second largest must be less than largest.

Array may have all equal elements → no second largest.

Array size may be small or large → aim for O(n) time, O(1) space.

Step 3: Approach / Steps

Method 1 – Two Traversals (Simple for beginners)

Traverse array to find largest element.

Traverse array again to find largest element smaller than the first largest → second largest.

Method 2 – Single Traversal (Optimal)

Initialize: first = -∞, second = -∞.

Traverse array:

If current > first → update second = first, first = current.

Else if current > second && current != first → update second = current.

After traversal:

If second is still -∞ → no second largest element.

Else → second is the answer.

Step 4: Things to Remember for Interviews

Edge Cases:

Array size < 2 → cannot find second largest.

All elements equal → no second largest.

Optimal Solution: Single traversal is preferred.

Time Complexity: O(n), Space Complexity: O(1)

Explainable Steps: Be ready to explain the logic with tracing an example.

Step 5: Example Trace

Array: [4, 2, 9, 1, 7]

Step	Element	first	second
1	4	4	-∞
2	2	4	2
3	9	9	4
4	1	9	4
5	7	9	7

Answer: 7 ✅ */


#include <iostream>       // 1
#include <climits>        // 2
using namespace std;      // 3

int main() {              // 4
    int arr[] = {4, 2, 9, 1, 7};        // 5
    int n = sizeof(arr)/sizeof(arr[0]); // 6

    int first = INT_MIN;   // 7
    int second = INT_MIN;  // 8

    for(int i = 0; i < n; i++) {       // 9
        if(arr[i] > first) {           // 10
            second = first;            // 11
            first = arr[i];            // 12
        } 
        else if(arr[i] > second && arr[i] != first) { // 13
            second = arr[i];           // 14
        }
    }

    if(second == INT_MIN)               // 15
        cout << "No second largest element\n"; // 16
    else
        cout << "Second Largest = " << second << endl; // 17

    return 0;                           // 18
}
