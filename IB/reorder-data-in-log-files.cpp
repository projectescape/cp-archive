unordered_map<string, int> pos;

bool compareStrings(string &a, string &b)
{
    int i = 0;
    string aSuffix = a.substr(a.find('-') + 1);
    string bSuffix = b.substr(b.find('-') + 1);

    for (; i < aSuffix.size() && i < bSuffix.size(); i++)
    {
        if (aSuffix[i] != bSuffix[i])
        {
            return aSuffix[i] < bSuffix[i];
        }
    }
    for (int j = 0; j < a.size() && j < b.size(); j++)
    {
        if (a[j] != b[j])
        {
            return a[j] < b[j];
        }
    }
    return true;
}

bool comp(string a, string b)
{
    string aSuffix = a.substr(a.find('-') + 1);
    string bSuffix = b.substr(b.find('-') + 1);

    if ((aSuffix[0] >= 'a' && aSuffix[0] <= 'z') && (bSuffix[0] >= 'a' && bSuffix[0] <= 'z'))
    {
        return compareStrings(a, b);
    }
    else if (aSuffix[0] >= 'a' && aSuffix[0] <= 'z')
    {
        return true;
    }
    else if (bSuffix[0] >= 'a' && bSuffix[0] <= 'z')
    {
        return false;
    }

    return pos[a] < pos[b];
}

vector<string> Solution::reorderLogs(vector<string> &A)
{

    for (int i = 0; i < A.size(); i++)
    {
        pos[A[i]] = i;
    }

    sort(A.begin(), A.end(), comp);

    return A;
}
