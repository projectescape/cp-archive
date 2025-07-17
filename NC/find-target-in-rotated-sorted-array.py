class Solution:
    def search(self, nums: List[int], target: int) -> int:

        def searchNum(start: int, end: int):
            if start > end:
                return -1

            mid = (start+end)//2

            if nums[mid] == target:
                return mid

            startNum = nums[start]
            endNum = nums[end]
            midNum = nums[mid]

            if startNum == target:
                return start

            if endNum == target:
                return end

            if startNum > midNum:
                if target < midNum or target > startNum:
                    return searchNum(start, mid-1)
                return searchNum(mid+1, end)
            elif midNum > endNum:
                if target > midNum or target < endNum:
                    return searchNum(mid+1, end)
                return searchNum(start, mid-1)
            else:
                if target < midNum:
                    return searchNum(start, mid-1)
                return searchNum(mid+1, end)

        return searchNum(0, len(nums)-1)
