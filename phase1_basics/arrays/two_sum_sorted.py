

""""
Problem: Two Sum II – Input Array Is Sorted
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Approach: Two-pointer approach (start from both ends)

Time Complexity: O(n) – Each pointer moves at most n steps combined
Space Complexity: O(1) – Constant space; no extra data structures used

Concepts to learn:

- How to use two pointers to traverse a sorted array efficiently
- Making decisions based on sorted properties (move left or right)
- In-place logic with no extra memory
- Real-world example of greedy narrowing down
- How to avoid rechecking pairs (each element used once at most)

Steps:
1. Initialize two pointers: left at 0, right at numbers.length - 1
2. While left < right:
   - Compute sum = numbers[left] + numbers[right]
   - If sum == target → return [left+1, right+1] (1-indexed)
   - If sum < target → increment left (need a bigger number)
   - If sum > target → decrement right (need a smaller number)

Why O(n)?
- Each iteration moves either left or right pointer once.
- So at most n steps total until pointers meet.
"""


class Solution(object):
    def twoSum(self, numbers, target):
        left = 0
        right = len(numbers) - 1

        while left < right:
            curr_sum = numbers[left] + numbers[right]
            if curr_sum == target:
                return [left + 1, right + 1]  # 1-indexed!
            elif curr_sum < target:
                left += 1
            else:
                right -=1
