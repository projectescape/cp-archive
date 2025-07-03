class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)

        ans = 1

        l, r = 0, 1

        count = {s[0]: 1}

        while r < len(s):
            count[s[r]] = count.get(s[r], 0) + 1

            if count[s[r]] > 1:
                while count[s[r]] != 1:
                    count[s[l]] -= 1
                    l += 1

            ans = max(ans, r-l+1)
            r += 1

        return ans
