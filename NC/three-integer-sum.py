class Solution:

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        def binSearch(start: int, end: int, prevSum: int):
            if start > end:
                return -1

            curr = int((start+end)/2)

            sum = prevSum+nums[curr]

            if sum == 0:
                return curr
            elif sum > 0:
                return binSearch(start, curr-1, prevSum)
            else:
                return binSearch(curr+1, end, prevSum)

        ans = set()

        print(nums)

        for i in range(len(nums)):
            for j in range(len(nums)-1, i, -1):
                k = binSearch(i+1, j-1, nums[i]+nums[j])
                print(nums[i], nums[k], nums[j])
                if k != -1:
                    ans.add((nums[i], nums[k], nums[j]))

        return [[i[0], i[1], i[2]] for i in ans]
