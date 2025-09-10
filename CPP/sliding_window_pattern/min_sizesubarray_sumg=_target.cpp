#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, sum = 0;
        int minLen = INT_MAX; // store result

        for (int r = 0; r < n; r++) {
            sum += nums[r];  // expand window to include nums[r]

            // shrink window while sum condition is satisfied
            while (sum >= target) {
                minLen = min(minLen, r - l + 1); // update result
                sum -= nums[l]; // remove leftmost element
                l++;            // shrink left boundary
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
