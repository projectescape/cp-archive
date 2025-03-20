int isFeasible(vector<int> &A, int numOfPages, int expectedNumberOfStudents)
{
    int students = 1, sum = 0;

    for (int i : A)
    {
        if (sum + i <= numOfPages)
        {
            sum += i;
        }
        else
        {
            students++;
            sum = i;
        }
    }

    return students <= expectedNumberOfStudents;
}

int Solution::books(vector<int> &A, int B)
{

    if (B > A.size())
        return -1;

    int minPages = INT_MIN, maxPages = 0;

    for (int i : A)
    {
        minPages = max(minPages, i);
        maxPages += i;
    }

    int result = 0;

    while (minPages <= maxPages)
    {
        int mid = (minPages + maxPages) / 2;
        if (isFeasible(A, mid, B))
        {
            result = mid;
            maxPages = mid - 1;
        }
        else
        {
            minPages = mid + 1;
        }
    }

    return result;
}

// [12, 34, 67, 90]