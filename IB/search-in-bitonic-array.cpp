int findPos(vector<int> &A, int B, int startIndex, int endIndex)
{
    if (startIndex > endIndex)
        return -1;

    int mid = (startIndex + endIndex) / 2;

    if (A[mid] == B)
        return mid;

    if (A[mid] < B)
        return findPos(A, B, mid + 1, endIndex);

    return findPos(A, B, startIndex, mid - 1);
}

int findPosInDecreasingVector(vector<int> &A, int B, int startIndex, int endIndex)
{
    if (startIndex > endIndex)
        return -1;

    int mid = (startIndex + endIndex) / 2;

    int valMid = A[mid];

    if (A[mid] == B)
        return mid;

    if (A[mid] < B)
        return findPosInDecreasingVector(A, B, startIndex, mid - 1);

    return findPosInDecreasingVector(A, B, mid + 1, endIndex);
}

int findBitonicPoint(vector<int> &A, int B, int startIndex, int endIndex)
{
    if (startIndex > endIndex)
        return -1;

    int mid = (startIndex + endIndex) / 2;

    if (mid - 1 >= 0)
    {
        if (A[mid - 1] < A[mid])
        {
            if (mid + 1 < A.size())
            {
                if (A[mid + 1] < A[mid])
                {
                    return mid;
                }
                else
                {
                    return findBitonicPoint(A, B, mid + 1, endIndex);
                }
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return findBitonicPoint(A, B, startIndex, mid - 1);
        }
    }

    return -1;
}

int Solution::solve(vector<int> &A, int B)
{

    int starPos = 0;

    int bitonicPoint = findBitonicPoint(A, B, 0, A.size() - 1);

    if (bitonicPoint == -1)
    {
        return findPos(A, B, 0, A.size() - 1);
    }

    int pos = findPos(A, B, 0, bitonicPoint);
    if (pos != -1)
        return pos;

    return findPosInDecreasingVector(A, B, bitonicPoint + 1, A.size() - 1);
}
