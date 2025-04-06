class Solution
{
public:
    string convert(string A, int B)
    {
        if (B == 1)
            return A;
        if (A.size() <= 1)
            return A;
        int numberToIncrement = (B - 1) * 2;

        string ans = "";

        for (int i = 0; i < B && i < A.size(); i++)
        {
            if (i == 0 || i == B - 1)
            {
                for (int j = i; j < A.size(); j += numberToIncrement)
                {
                    ans += A[j];
                }
            }
            else
            {
                ans += A[i];
                int partialIncrement = numberToIncrement - 2 * i;
                int j = i;
                while (true)
                {
                    if (j + partialIncrement < A.size())
                    {
                        j = j + partialIncrement;
                        ans += A[j];
                    }
                    else
                    {
                        break;
                    }
                    if (j + numberToIncrement - partialIncrement < A.size())
                    {
                        j = j + numberToIncrement - partialIncrement;
                        ans += A[j];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};