class Solution:
    def findMin(self, nums: List[int]) -> int:

        def findMin(start: int, end: int):

            if start == end:
                return nums[start]

            if start == end-1:
                return min(nums[start], nums[end])

            mid = int((start+end)/2)

            if nums[start] > nums[mid]:
                return findMin(start, mid)

            elif nums[mid] > nums[end]:
                return findMin(mid, end)

            return nums[start]

        return findMin(0, len(nums)-1)
