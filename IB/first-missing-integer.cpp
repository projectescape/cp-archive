int Solution::firstMissingPositive(vector<int> &A)
{
    int answer = A.size() + 1;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] <= 0)
        {
            A[i] = INT_MAX;
        }
    }

    for (int i = 0; i < A.size(); i++)
    {
        int absValue = abs(A[i]);
        if (absValue <= A.size())
        {
            A[absValue - 1] = abs(A[absValue - 1]) * -1;
        }
    }

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > 0)
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}