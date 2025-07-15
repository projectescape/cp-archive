class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 0:
            return True
        stack = [s[0]]

        reverseBracketMap = {
            ")": "(",
            "]": "[",
            "}": "{"
        }

        bracketSet = {"[", "{", "("}

        for index in range(1, len(s)):
            char = s[index]
            if char in bracketSet:
                stack.append(char)
            else:
                bracket = reverseBracketMap[char]
                if len(stack) == 0:
                    return False
                elif stack[-1] == bracket:
                    stack.pop()
                else:
                    return False

        if len(stack) != 0:
            return False

        return True
