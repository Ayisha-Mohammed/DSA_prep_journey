# 🎯 Problem: Two Sum
# Goal: Find two numbers such that they add up to the target
# Return their indices (exactly one valid answer exists)

# ✅ Approach: Hash Map (Dictionary) + Complement Logic

# 🗂️ 1. Use a dictionary to store numbers we’ve already seen
# Key: number, Value: its index
# This helps us find complements in O(1) time

# 💡 2. For every number in the array:
#    - Calculate complement = target - current_number
#    - Check if this complement exists in the dictionary
#    - If it does, return [index_of_complement, current_index]
#    - Otherwise, store the current number and its index in the dictionary

# 🔁 3. Why we don't reuse the same element:
#    - Because we check the complement BEFORE adding the current number to the dictionary
#    - So the same element won't be used twice

# ⏱️ 4. Time Complexity:
#    - O(n) to iterate through the array once
#    - O(1) dictionary lookup per element
#    - Overall: O(n) time, O(n) space for dictionary

# 🧪 5. Edge Cases:
#    - Input always valid as per constraints (length ≥ 2)
#    - Only one solution exists
#    - Negative numbers and zero are allowed

# 🧠 6. Pattern Name: Hash Map + Complement Lookup
#    - Also called "Lookup Before Insert" pattern
#    - Useful for problems that ask to find pairs that add up to a value

# 📌 7. Key Takeaway:
#    - Hash maps let you remember what you've seen so far
#    - Check for the needed pair while iterating to avoid O(n²)
class Solution(object):
    def twoSum(self, nums, target):
     seen = {} 
     for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i



#Input
#nums =[2,7,11,15]