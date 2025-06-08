class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numset = {}
        for index, num in enumerate(nums):
            numset[num] = index

        for index, num in enumerate(nums):
            secondNum = target-num
            secondIndex = numset.get(secondNum, -1)
            if index == secondIndex:
                continue
            if secondIndex != -1:
                return [index, secondIndex]

        return []
