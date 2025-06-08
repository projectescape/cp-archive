class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sCounts = {}
        tCounts = {}

        for c in s:
            sCounts[c] = sCounts.get(c, 0) + 1

        for c in t:
            tCounts[c] = tCounts.get(c, 0) + 1

        if len(sCounts) != len(tCounts):
            return False

        for key in sCounts:
            if sCounts.get(key, 0) != tCounts.get(key, 0):
                return False

        return True
