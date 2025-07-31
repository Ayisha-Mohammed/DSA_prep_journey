
# 🔁 Problem: Rotate an array to the right by k steps
# Example:
# Input : nums = [1, 2, 3, 4, 5, 6, 7], k = 3
# Output:        [5, 6, 7, 1, 2, 3, 4]

# ✅ Step-by-step logic:
# 1. Reverse the entire array
# 2. Reverse the first k elements
# 3. Reverse the remaining n - k elements

# ❗ k might be greater than n
# So, we do: k %= n
# This handles cases like k = 10 when n = 7
# Because rotating by n brings us back to the same array

# 🧠 Example trace:
# Original:           [1, 2, 3, 4, 5, 6, 7]
# After full reverse: [7, 6, 5, 4, 3, 2, 1]
# Reverse first 3:    [5, 6, 7, 4, 3, 2, 1]
# Reverse rest:       [5, 6, 7, 1, 2, 3, 4]

# ✅ Key concepts to learn:
# - Modulo usage for bounds: k %= n
# - Reversing subarrays using two pointers
# - In-place array manipulation
# - Think in transformations (break big task into smaller reversible steps)

class Solution(object):
    def rotate(self, nums, k):
        n=len(nums)
        k%=n
        def reverse(left,right):
            while left < right:
                nums[left] ,nums[right]=  nums[right] ,nums[left]
                left+=1
                right-=1
        reverse(0,n-1)
        reverse(0,k-1)
        reverse(k,n-1)
        