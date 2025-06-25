class Solution:

    def getLongestSequence(self, numSet, numTraversed, num):
        if numTraversed.get(num, False) == True:
            return 1

        ans = 1

        numTraversed[num] = True

        curr = num - 1

        while curr in numSet:
            ans += 1
            numTraversed[curr] = True
            curr -= 1

        curr = num + 1

        while curr in numSet:
            ans += 1
            numTraversed[curr] = True
            curr += 1

        return ans

    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set()
        numTraversed = {}
        for num in nums:
            numSet.add(num)

        ans = 0

        for num in numSet:
            ans = max(ans, self.getLongestSequence(numSet, numTraversed, num))

        return ans
