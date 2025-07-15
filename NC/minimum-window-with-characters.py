# This is an unotimized solution
#  This can be improved by using a sliding window approach

class Solution:

    def compMaps(self, count_t, count_s):
        for key in count_t:
            if count_t[key] > count_s.get(key, 0):
                return False

        return True

    def minWindow(self, s: str, t: str) -> str:
        count_t = {}
        for char in t:
            count_t[char] = count_t.get(char, 0) + 1

        count_s = {}
        for char in s:
            count_s[char] = count_s.get(char, 0) + 1

        if self.compMaps(count_t, count_s):
            ans = s
        else:
            return ""

        def updateAns(start, end, count_map):
            if start > end:
                return

            if self.compMaps(count_t, count_map):
                nonlocal ans
                currAns = s[start:(end+1)]
                if len(currAns) < len(ans):
                    ans = currAns
                start_char = s[start]
                end_char = s[end]
                count_map[start_char] -= 1
                updateAns(start+1, end, count_map.copy())
                count_map[end_char] -= 1
                count_map[start_char] += 1
                updateAns(start, end-1, count_map.copy())

        updateAns(0, len(s)-1, count_s.copy())

        return ans
