int reverseNumberBinaryAndPad(int n, int length)
{
    vector<int> binary;
    while (n > 0)
    {
        binary.push_back(n % 2);
        n /= 2;
    }
    while (binary.size() < length)
    {
        binary.push_back(0);
    }
    int ans = 0;
    for (int i = 0; i < binary.size(); i++)
    {
        ans = ans << 1;
        ans = ans | binary[i];
    }
    return ans;
}

int Solution::solve(int A)
{
    if (A == 0)
        return 0;
    if (A == 1)
        return 1;

    int numOfDigits = 0;
    int numOfCombination = 0;

    for (numOfDigits = 1;; numOfDigits++)
    {
        int numToAdd = pow(2, (numOfDigits - 1) / 2);
        if (numOfCombination + numToAdd >= A)
        {
            break;
        }
        numOfCombination += numToAdd;
    }

    int numberToIncrement = A - numOfCombination - 1;

    int ans = 1;

    for (int i = 0; i < numOfDigits - 1; i++)
    {
        ans = ans << 1;
    }
    ans += 1;

    if (numberToIncrement != 0)
    {
        ans = ans | reverseNumberBinaryAndPad(numberToIncrement, (numOfDigits + 1) / 2);
        ans = ans | (numberToIncrement << ((numOfDigits) / 2));
    }

    return ans;
}

// 1  - 1
// 11 - 1
// 101 - 2
// 111
// 1001 - 2
// 1111
// 10001  - 4
// 10101
// 11011
// 11111
// 100001 - 4
// 101101
// 110011
// 111111
// 1000001 - 8
// 1001001
// 1010101
// 1011101
// 1100011
// 1101011
// 1110111
// 1111111
