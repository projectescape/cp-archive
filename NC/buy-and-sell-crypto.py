class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        maxAtRightFromPos = [0 for i in range(len(prices))]

        currMax = -1

        for i in range(len(prices)-2, -1, -1):
            maxAtRightFromPos[i] = max(prices[i+1], currMax)
            currMax = max(currMax, maxAtRightFromPos[i])

        ans = 0

        for i in range(len(prices)-1):
            ans = max(ans, maxAtRightFromPos[i]-prices[i])

        return ans


class SolutionWithBetterSpaceComplexity:
    def maxProfit(self, prices: List[int]) -> int:

        l, r = 0, 1
        ans = 0

        while r < len(prices):
            if prices[l] < prices[r]:
                ans = max(ans, prices[r] - prices[l])
            else:
                l = r
            r += 1

        return ans
