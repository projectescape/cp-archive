class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans = min(len(s), max(k, 1))

        l, r = 0, 1

        currChar = s[0]

        count = {
            s[l]: 1
        }

        replace_count = 0

        def reCalcStartingPoint():
            nonlocal l, currChar, replace_count
            maxCharCount = 0
            maxChar = 'a'

            for key in count:
                if count[key] > maxCharCount:
                    maxCharCount = count[key]
                    maxChar = key

            if r-l+1-maxCharCount <= k:
                currChar = maxChar
                replace_count = r-l+1-maxCharCount
                return

            while l <= r:

                if r-l+1-maxCharCount <= k:
                    break

                else:
                    charToRemove = s[l]
                    count[charToRemove] -= 1
                    if count[charToRemove] == 0:
                        count.pop(charToRemove)
                    l += 1

                maxCharCount = 0
                for key in count:
                    if count[key] > maxCharCount:
                        maxCharCount = count[key]
                        maxChar = key

            currChar = maxChar
            replace_count = r-l+1-maxCharCount

        while r < len(s):
            count[s[r]] = count.get(s[r], 0) + 1
            if s[r] == currChar:
                ans = max(ans, r-l+1)
            else:
                replace_count += 1
                if replace_count <= k:
                    ans = max(ans, r-l+1)
                else:
                    reCalcStartingPoint()
                    ans = max(ans, r-l+1)
            r += 1

        return ans
