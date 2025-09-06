#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // number -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            // Found the pair
            return {mp[complement], i};
        }
        mp[nums[i]] = i; // store current number with its index
    }
    return {}; // fallback (problem guarantees a solution exists)
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}


/*Name / Approach

Hash Map / Dictionary Approach (Optimal Approach)

Idea:

While iterating through the array, for each element num, check if its complement (target - num) has already been seen.

Use a hash map (or dictionary) to store numbers you’ve seen along with their indices.

If the complement exists, you found the pair.

Otherwise, store the current number in the map and continue.

Workflow / Algorithm

Initialize an empty hash map: map = {}

Loop through the array:

Compute complement = target - nums[i]

Check: if complement exists in map

If yes → return [map[complement], i]

If no → store nums[i] in the map with its index

End of loop → if no pair found, return empty (though problem guarantees one solution)

Why This Works

The hash map allows O(1) lookup to check if the complement exists.

You only loop through the array once, so it’s O(n) time.

The map stores previously seen numbers → no need to check all pairs.

Key Terms

Complement: target - current_number

Hash Map / Dictionary: Data structure for fast key-value lookups

One-pass solution: You find the answer in a single pass through the array~

*/