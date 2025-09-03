#include <iostream>
#include <vector>
#include <algorithm>  // for reverse
using namespace std;



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;                    // handle k > n
        reverse(nums.begin(), nums.end());       // step 1: reverse whole array
        reverse(nums.begin(), nums.begin() + k); // step 2: reverse first k elements
        reverse(nums.begin() + k, nums.end());   // step 3: reverse remaining n-k elements
    }
};
