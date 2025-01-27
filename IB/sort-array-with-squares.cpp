vector<int> absoluteSortedArray(int midIndex, vector<int> &A)
{

    vector<int> answer;

    int i = midIndex - 1, j = midIndex;

    for (; i >= 0 && j < A.size();)
    {
        if (abs(A[i]) < A[j])
        {
            answer.push_back(A[i]);
            i--;
        }
        else
        {
            answer.push_back(A[j]);
            j++;
        }
    }

    if (i >= 0)
    {
        for (; i >= 0; i--)
        {
            answer.push_back(A[i]);
        }
    }
    else
    {
        for (; j < A.size(); j++)
        {
            answer.push_back(A[j]);
        }
    }

    return answer;
}

vector<int> Solution::solve(vector<int> &A)
{
    int firstPositiveNumberIndex = A.size();
    for (int index = 0; index < A.size(); index++)
    {
        if (A[index] >= 0)
        {
            firstPositiveNumberIndex = index;
            break;
        }
    }

    vector<int> answer = absoluteSortedArray(firstPositiveNumberIndex, A);

    for (int i = 0; i < answer.size(); i++)
    {
        answer[i] = answer[i] * answer[i];
    }
    return answer;
}
