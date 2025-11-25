class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;

        for (string t : tokens)
        {
            if (t == "+")
            {
                int val = s.top();
                s.pop();
                s.top() += val;
            }
            else if (t == "-")
            {
                int val = s.top();
                s.pop();
                s.top() -= val;
            }
            else if (t == "*")
            {
                int val = s.top();
                s.pop();
                s.top() *= val;
            }
            else if (t == "/")
            {
                int val = s.top();
                s.pop();
                s.top() /= val;
            }
            else
            {
                s.push(stoi(t));
            }
        }

        return s.top();
    }
};
