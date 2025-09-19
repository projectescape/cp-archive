class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> newStack;

        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}};

        for (char c : s)
        {
            if (bracketMap.find(c) == bracketMap.end())
            {
                newStack.push(c);
            }
            else if (newStack.size() > 0)
            {
                if (newStack.top() == bracketMap[c])
                {
                    newStack.pop();
                }
                else
                {
                    newStack.push(c);
                }
            }
            else
            {
                newStack.push(c);
            }
        }
        if (newStack.size() > 0)
        {
            return false;
        }
        return true;
    }
};
