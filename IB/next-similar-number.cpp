string getJustBiggerNum(string a)
{
    string ans = a;
    int currMaxIndex = a.size() - 1;
    for (int i = a.size() - 2; i >= 0; i--)
    {
        if (a[i] < a[currMaxIndex])
        {
            int justMaxIndex = currMaxIndex;
            for (int j = i + 1; j < a.size(); j++)
            {
                if (a[i] < a[j] && a[j] < a[justMaxIndex])
                {
                    justMaxIndex = j;
                }
            }
            swap(ans[i], ans[justMaxIndex]);
            sort(ans.begin() + i + 1, ans.end());
            break;
        }
        else
        {
            currMaxIndex = i;
        }
    }
    return ans;
}

string Solution::solve(string A)
{
    string ans = getJustBiggerNum(A);
    if (A.compare(ans) == 0)
    {
        return "-1";
    }
    return ans;
}
