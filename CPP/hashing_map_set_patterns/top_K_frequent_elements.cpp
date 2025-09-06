/* MEDIUM.......................................M
🔹 Problem Statement

Given:
An integer array nums
An integer k

Task:
Return the k elements that appear most frequently in the array.
You can return the answer in any order.

Example:
nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Explanation:
1 appears 3 times → most frequent
2 appears 2 times → second most frequent
3 appears 1 time → ignored

🔹 Idea / Approach
Count frequency of each number using unordered_map<int,int>.
Use a max heap (priority_queue) to sort numbers by their frequency.
Pop top k elements from the heap → these are the most frequent elements.
*/


/*
STEP 1:
unordered_map<int,int> freq;
for (int num : nums) freq[num]++;
unordered_map<int,int> freq; → maps each number to its frequency.

for (int num : nums) → loop through each number in nums.
freq[num]++ → increment the count for num.

Example (nums = [1,1,1,2,2,3]):

ini
Copy code
freq = { 1:3, 2:2, 3:1 }
*/

/*
STEP 2: 
Step 2: Push into Max Heap
priority_queue<pair<int,int>> pq; // (freq, num)
for (auto it : freq) {
    pq.push({it.second, it.first});
}
priority_queue<pair<int,int>> pq; → max heap of pairs.
pair.first = frequency
pair.second = number
for (auto it : freq) → loop through each (num, frequency) in map.
pq.push({it.second, it.first}); → push (frequency, number) into the heap.
Heap structure (top → bottom):

(3,1)  ← largest frequency
(2,2)
(1,3)
*/

/*
STEP 3:
Step 3: Extract Top K Elements
vector<int> result;
for (int i = 0; i < k; i++) {
    result.push_back(pq.top().second);
    pq.pop();
}

vector<int> result; → stores the final answer.
for (int i = 0; i < k; i++) → repeat k times.
pq.top() → largest frequency pair at the top of heap.
pq.top().second → get the number (not frequency).
result.push_back(...) → add it to result.
pq.pop() → remove the top element from heap.

Step-by-step (k=2):
Top = (3,1) → add 1 to result → result = [1] → pop.
Top = (2,2) → add 2 to result → result = [1,2] → pop.

*/

/*
STEP4:
return result;
Returns [1,2] → top k frequent elements.
*/

/*
STEP 5:
int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = topKFrequent(nums, k);
    for (int x : ans) cout << x << " ";
    cout << endl;
}
Defines input array nums and k.
Calls topKFrequent(nums,k) → stores result in ans.
Loops through ans and prints each element.
Prints newline.

Output:
Copy code
1 2
*/



#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Function to return top k frequent elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Count frequency of each number
    unordered_map<int,int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    // Step 2: Create a max heap (priority_queue) of pairs (frequency, number)
    priority_queue<pair<int,int>> pq; // max heap: largest frequency on top
    for (auto it : freq) {
        pq.push({it.second, it.first}); // push (frequency, number)
    }

    // Step 3: Extract top k elements from the heap
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(pq.top().second); // get the number
        pq.pop(); // remove it from heap
    }

    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3}; // input array
    int k = 2; // number of top frequent elements

    vector<int> ans = topKFrequent(nums, k); // call function

    // Print the result
    for (int x : ans) cout << x << " ";
    cout << endl; // Expected output: 1 2
}
