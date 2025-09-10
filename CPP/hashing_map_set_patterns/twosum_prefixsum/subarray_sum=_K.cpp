//  prefixsum + hashmap
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1; // base case: sum from start
        
        int prefixSum = 0, count = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // check if prefixSum-k exists
            if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
                count += prefixCount[prefixSum - k];
            }
            
            // store prefixSum in map
            prefixCount[prefixSum]++;
        }
        
        return count;
    }
};
