int Solution::solve(string A)
{
    stack<char> s;
    for (char c : A)
    {
        if (s.empty())
        {
            s.push(c);
        }
        else
        {
            if (c == '(')
            {
                s.push(c);
            }
            else
            {
                if (s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(c);
                }
            }
        }
    }
    return s.size();
}
