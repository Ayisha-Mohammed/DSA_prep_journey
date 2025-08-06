# ✅ Use two pointers: 'read' scans input, 'write' builds result  
# → One pointer (`i`) goes through all elements (read).  
# → Another (`k` or `write`) keeps track of where to place valid (non-val) items.

# ✅ Modify the array in-place (no extra array used)  
# → You overwrite the same `nums` array without using extra memory.

# ✅ Remaining element order can change — that's okay  
# → You don’t need to keep the original order of the elements.  
# → Example: [0,1,2,2,3] can become [1,3,_,_,_] — order doesn't matter.

# ✅ Return how many elements are NOT equal to val (length of new array)  
# → The function should return the count `k` of all elements that are **not** equal to `val`.

# ✅ Values beyond returned length don’t matter (can be ignored)  
# → After index `k`, whatever remains in the array isn’t checked or judged.  
# → Judge only looks at the first `k` elements.

# ✅ O(n) time — we scan each element once  
# → You loop through the array only once (single pass) → linear time.

# ✅ O(1) space — no extra memory, just two pointers  
# → You don’t use another list or array, just a couple of variables → constant space.

# ✅ Pattern to remember: keep elements based on condition using two pointers  
# → Very common approach in interview problems: use two indices  
#    (1 reads through input, 1 writes only valid items).


class Solution(object):
    def removeElement(self, nums, val):
        i = 0  # write pointer
        for j in range(len(nums)):  # read pointer
            if nums[j] != val:
                nums[i] = nums[j]  # write valid number at position i
                i += 1  # move write pointer
        return i  # i is the new length

nums = [0,1,2,2,3,0,4,2], val = 2