def lengthOfLongestSubstring(s):
    char_index_map = {}     # stores characters and their last seen index
    left = 0                # start of the current window
    max_length = 0          # result

    for right in range(len(s)):                # move right pointer
        if s[right] in char_index_map and char_index_map[s[right]] >= left:
            left = char_index_map[s[right]] + 1

        char_index_map[s[right]] = right       # update the last seen index
        max_length = max(max_length, right - left + 1)  # update result

    return max_length


# Purpose:
# - To find the length of the longest substring without repeating characters.

# Concept:
# - Use a variable-size sliding window to maintain a window of unique characters.
# - Expand the window by moving the right pointer.
# - Shrink the window by moving the left pointer when a duplicate character is found.

# Why sliding window?
# - We want to examine all possible substrings, but doing it in a brute-force way (checking all substrings) is inefficient.
# - Sliding window allows us to move through the string efficiently, only processing each character once.

# Why variable-sized?
# - The size of the window changes dynamically.
# - It grows when we find unique characters.
# - It shrinks from the left when a duplicate character is found inside the current window.

# What do we track?
# - Left pointer: start of the window.
# - Right pointer: end of the window (moves character by character).
# - A hash map to store the last seen index of each character.

# Key logic:
# - If the current character has been seen **inside the current window**, we move the left pointer to the right of its last occurrence.
# - This ensures that the window always has **unique characters**.

# Time Complexity:
# - O(n), where n is the length of the string.
# - Each character is processed at most twice: once by the right pointer, once by the left.
# - Hash map lookups and updates are O(1).

# Space Complexity:
# - O(min(n, m)), where:
#   - n is the length of the string,
#   - m is the character set size (e.g., 26 for lowercase English, 128 for ASCII).
# - We store characters and their indices in a dictionary.
