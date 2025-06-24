class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        totalProduct = 1
        hasZero = 0

        for i in nums:
            if i != 0:
                totalProduct *= i
            else:
                hasZero += 1

        ans = []

        for i in nums:
            if hasZero == 0:
                ans.append(int(totalProduct/i))
            else:
                if hasZero == 1:
                    if i == 0:
                        ans.append(int(totalProduct))
                    else:
                        ans.append(0)
                else:
                    ans.append(0)

        return ans
