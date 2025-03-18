vector<vector<int>> Solution::prettyPrint(int A)
{
    int numOfElements = A * 2 - 1;
    vector<vector<int>> a(numOfElements, vector<int>(numOfElements, A));

    for (int i = 1; i < numOfElements - 1; i++)
    {
        int subTillIndex = i;
        if (subTillIndex >= A)
        {
            subTillIndex = numOfElements - i - 1;
        }
        int addFromIndex = numOfElements - subTillIndex;
        for (int j = 1; j < numOfElements; j++)
        {
            a[i][j] = a[i][j - 1];
            if (j <= subTillIndex)
            {
                a[i][j] = a[i][j] - 1;
            }
            if (j >= addFromIndex)
            {
                a[i][j] = a[i][j] + 1;
            }
        }
    }
    return a;
}
