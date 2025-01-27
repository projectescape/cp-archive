vector<int> Solution::findOccurences(vector<int> &A)
{
    map<int, int> count;
    for (int i = 0; i < A.size(); i++)
    {
        if (count.find(A[i]) != count.end())
        {
            count[A[i]] = count[A[i]] + 1;
        }
        else
        {
            count[A[i]] = 1;
        }
    }
    vector<int> ans;
    for (map<int, int>::iterator it = count.begin(); it != count.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}
