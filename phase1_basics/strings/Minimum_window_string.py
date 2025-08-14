

if not s or not t:
            return ""
        
        target_map = Counter(t)
        window_map = {}
        have, need = 0, len(target_map)
        res, res_len = [-1, -1], float("inf")
        left = 0

        for right in range(len(s)):
            c = s[right]
            window_map[c] = window_map.get(c, 0) + 1

            if c in target_map and window_map[c] == target_map[c]:
                have += 1

            while have == need:
                if (right - left + 1) < res_len:
                    res = [left, right]
                    res_len = right - left + 1

                window_map[s[left]] -= 1
                if s[left] in target_map and window_map[s[left]] < target_map[s[left]]:
                    have -= 1
                left += 1

        l, r = res
        return s[l:r+1] if res_len != float("inf") else ""
