int findPos(const vector<int> &A, int B, int startIndex, int endIndex)
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

int findRotationPoint(const vector<int> &A, int startIndex, int endIndex)
{
    if (startIndex > endIndex)
        return -1;

    int mid = (startIndex + endIndex) / 2;

    if (mid - 1 >= 0)
    {
        if (A[mid - 1] > A[mid])
        {
            return mid;
        }
        else
        {
            int left = findRotationPoint(A, startIndex, mid - 1);
            int right = findRotationPoint(A, mid + 1, endIndex);
            if (left != -1)
                return left;
            if (right != -1)
                return right;
            return -1;
        }
    }

    return -1;
}

int Solution::search(const vector<int> &A, int B)
{

    int rotationPoint = findRotationPoint(A, 0, A.size() - 1);

    if (rotationPoint == -1)
    {
        return findPos(A, B, 0, A.size() - 1);
    }

    int left = findPos(A, B, 0, rotationPoint - 1);
    if (left != -1)
        return left;

    return findPos(A, B, rotationPoint, A.size() - 1);
}