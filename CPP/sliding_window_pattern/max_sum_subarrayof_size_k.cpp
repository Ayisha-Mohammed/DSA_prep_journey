// FIXED SIZE WINDOW . Window = always K.

/*Idea:
Maintain a window of size k.
As you slide right:
Add the new element (arr[r])
Remove the old element (arr[l])
This way you don’t recompute sum from scratch.
*/

/*
Algorithm:
Initialize l = 0, window_sum = 0, max_sum = INT_MIN.
Iterate r from 0 → n-1:
Add arr[r] to window_sum.
If window size < k → keep expanding.
If window size == k →
Update max_sum = max(max_sum, window_sum)
Remove arr[l] from sum and increment l (shrink left).
Return max_sum.
*/

/*
Dry Run:
arr = [2, 1, 5, 1, 3, 2], k = 3
Start: l=0, window_sum=0, max_sum=-inf
r=0 → add 2 → window=[2] → sum=2
r=1 → add 1 → window=[2,1] → sum=3
r=2 → add 5 → window=[2,1,5] → sum=8 → window full → max=8
→ remove arr[l]=2 → sum=6, l=1
r=3 → add 1 → window=[1,5,1] → sum=7 → max=8
→ remove arr[l]=1 → sum=6, l=2
r=4 → add 3 → window=[5,1,3]  sum=9 → max=9
→ remove arr[l]=5 → sum=4, l=3
r=5 → add 2 → window=[1,3,2] → sum=6 → max=9
👉 Final answer = 9
*/

#include <iostream>
#include<vector>
using namespace std;

int maxSumSubarrayOfSizeK(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, window_sum = 0, max_sum = INT_MIN;

    for (int r = 0; r < n; r++) {
        window_sum += arr[r];  // expand window

        if (r - l + 1 == k) {  // window is full
            max_sum = max(max_sum, window_sum);
            window_sum -= arr[l]; // remove left element
            l++; // move left
        }
    }
    return max_sum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << maxSumSubarrayOfSizeK(arr, k) << endl; // Output: 9
    return 0;
}







/*

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long window_sum = 0;

        // sum of the first k elements
        for (int i = 0; i < k; i++) window_sum += nums[i];
        long long max_sum = window_sum;

        // slide the window
        for (int r = k; r < n; r++) {
            window_sum += nums[r] - nums[r - k];
            if (window_sum > max_sum) max_sum = window_sum;
        }

        return static_cast<double>(max_sum) / k;  // <-- average
    }
};
*/