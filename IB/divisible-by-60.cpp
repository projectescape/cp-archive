int Solution::divisibleBy60(vector<int> &A)
{

    if (A.size() == 1 && A[0] == 0)
        return 1;

    // Check if divisible by 10
    int flag = 0;
    for (int i : A)
    {
        if (i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        return 0;
    }

    // Check if divisible by 3

    flag = 0;
    for (int i : A)
    {
        flag = flag + i;
        flag = flag % 3;
    }
    if (flag != 0)
    {
        return 0;
    }

    // Check if divisible by 2
    flag = 0;

    for (int i : A)
    {
        if (i % 2 == 0)
            flag++;
    }

    if (flag > 1)
        return 1;

    return 0;
}