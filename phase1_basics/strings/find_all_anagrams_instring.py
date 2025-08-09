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