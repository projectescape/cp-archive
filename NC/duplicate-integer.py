class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        mapping = {}
        for number in nums:
            mapping[number] = 1 + mapping.get(number, 0)
            if (mapping[number]) > 1:
                return True
        return False
