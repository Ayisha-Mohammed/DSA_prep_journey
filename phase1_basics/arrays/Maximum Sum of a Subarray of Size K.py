# 💡 Goal: Find the maximum average of any subarray of length k.
# 🪟 Sliding Window: Efficient technique for problems involving subarrays with fixed or variable lengths.
# 🔢 Initial Step: Compute the sum of the first k elements → this is your first window.
# 🔄 Window Movement:
# At each step, remove the element that's leaving the window (from the left),
# Add the new element that's entering the window (from the right).
# ⚡ Why Efficient:
# Instead of recalculating the sum of k elements at every step (which would take O(k) per step → O(nk) total),
# You reuse the previous sum and do just 2 operations per move: one subtraction, one addition → O(n) time total.
# 🧮 Final Step: Track the highest sum seen and return its average (i.e., max_sum / k).



class Solution(object):
    def findMaxAverage(self, nums, k):
      current_sum = sum(nums[:k])
      max_sum = current_sum
      for i in range(k, len(nums)):
        current_sum = current_sum - nums[i - k] + nums[i]
        max_sum = max(max_sum, current_sum)
      return max_sum/float(k)
    

# Input: nums = [1,12,-5,-6,50,3], k = 4
# Output: 12.75000
# Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

# ✅ Benefits of Sliding Window Approach (Fixed Size k)
# ⚡ 1. Time Efficiency — From O(n×k) → O(n)
# Brute-force: For each possible subarray of size k, sum k elements → O(n×k)

# Sliding Window:

# You compute the first sum once

# Then reuse it with just 1 subtraction and 1 addition per step → O(n)

# 📉 Significantly faster, especially for large inputs.

# 🧠 2. Less Redundant Work
# In brute force, you keep re-adding the same numbers again and again.

# In sliding window, you reuse most of the previous calculation.

# 🧮 3. Simple and Clean Logic
# Once understood, it’s a very intuitive pattern.

# No nested loops — just a single pass with a running sum.

# 🧰 4. Widely Applicable
# Useful in many problems:

# Max/Min sum of subarray

# Longest substring with conditions

# Binary problems (e.g., number of 1s in a window)

# 💾 5. Space Efficient
# No need to store intermediate subarrays or extra memory.

# Constant space — just a few variables.

