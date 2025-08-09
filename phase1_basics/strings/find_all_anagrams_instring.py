from collections import Counter

def findAnagrams(s, p):
    res = []
    len_p = len(p)
    p_count = Counter(p)             # frequency of pattern
    window_count = Counter(s[:len_p]) # frequency of first window in s

    # check first window
    if window_count == p_count:
        res.append(0)

    for i in range(len_p,len_s):
        window_count[s[i]] += 1
        outgoing = s[i - len_p]
        window_count[outgoing] -= 1
        if window_count[outgoing] == 0:
            del window_count[outgoing]
        if window_count == p_count:
            res.append(i - len_p + 1)
    return res

# s = "cbaebabacd"
#     #0123456789
# p = "abc"

# Purpose
# The goal is to find all starting indices in the string s where the substring is an anagram of the string p.
# For example:
# s = "cbaebabacd", p = "abc" → Anagrams start at indices [0, 6].

# Concept Used
# Sliding Window
# We take a "window" of length len(p) and slide it across s.
# At each position, we check if the characters in the window form an anagram of p.

# Character Frequency Counting
# Instead of sorting (which is slow), we count how many times each character appears in the window and compare it to p's character count.

# Why Sliding Window Works
# If we compare every substring of length len(p) separately (by re-counting characters each time), it’s slow (O(n * len(p))).
# The sliding window lets us reuse most of the counts:

# Add the new incoming character (right side of the window)
# Remove the outgoing character (left side of the window)
# This keeps the operation per slide at O(1) for count update.

# Workflow

# Precompute p's character count using a Counter (like a frequency map).
# Initialize first window of s with length len(p).
# Compare first window's count with p's count → if equal, record index 0.

# Slide the window:

# Add incoming character (right end of window).
# Remove outgoing character (left end of window).
# If any character’s count becomes 0, delete it from the map to keep comparison clean.
# If after sliding, the counts match p’s count → record starting index.
# Continue until the end of s.

# Time Complexity

# O(n), where n = len(s)
# We traverse each character once and update counts in O(1) time per step.
# Comparing two Counter objects is O(26) in the worst case (fixed alphabet size), which is constant time.
# Why not O(n * m)?
# Because we reuse frequency counts instead of recomputing from scratch for each window.

# Space Complexity

# O(1) in terms of alphabet size (only 26 lowercase letters), but practically O(k) where k is the number of unique characters in p and the current window.

# Points to Remember

# Window Size = Length of p (fixed)
# Only compare frequency maps (not sorted strings) — much faster.
# Delete keys with zero count to make equality check faster.
# First window is special — you compare it before starting the slide.
# Sliding window → "Add right, remove left" each step.
# Return list of starting indices.
# Handles cases where p is longer than s (returns []).

