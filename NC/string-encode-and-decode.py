class Solution:
    def encode(self, strs: List[str]) -> str:
        newList = []
        for s in strs:
            newList.append(f"{len(s)}#")
            newList.append(s)

        ans = "".join(newList)

        print(ans)

        return ans

    def decode(self, s: str) -> List[str]:

        res = []

        i = 0
        while i < len(s):
            numString = ""

            while s[i] != "#":
                numString += s[i]
                i += 1

            strLength = int(numString)

            i += 1
            # if strLength!=0:
            res.append(s[i:i+strLength])
            i += strLength

        return res
