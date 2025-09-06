/* Problem:
Given an integer array nums, return true if any value appears at least twice, and false if every element is distinct.

Idea:
Use a hash set (unordered_set<int>).
As we iterate:
If number already in set → return true.
Else → insert it.
End of loop → return false.*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return true; // already exists
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,1};
    cout << (containsDuplicate(nums) ? "true" : "false") << endl;
}
