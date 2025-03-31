// Very idiotic questions, with very idiotic edge cases
// I could have spent more time on handling all the edge cases, but that would have been time wasted
// Writing the code and moving on

#include <bits/stdc++.h>
using namespace std;

int solve(string A, string B)
{
    map<string, int> numberMapping = {{"zero", 0},
                                      {"one", 1},
                                      {"two", 2},
                                      {"three", 3},
                                      {"four", 4},
                                      {"five", 5},
                                      {"six", 6},
                                      {"seven", 7},
                                      {"eight", 8},
                                      {"nine", 9},
                                      {"ten", 10},
                                      {"eleven", 11},
                                      {"twelve", 12},
                                      {"thirteen", 13},
                                      {"fourteen", 14},
                                      {"fifteen", 15},
                                      {"sixteen", 16},
                                      {"seventeen", 17},
                                      {"eighteen", 18},
                                      {"nineteen", 19},
                                      {"twenty", 20},
                                      {"thirty", 30},
                                      {"forty", 40},
                                      {"fifty", 50},
                                      {"sixty", 60},
                                      {"seventy", 70},
                                      {"eighty", 80},
                                      {"ninety", 90}};
    map<string, long long>
        multiplierMapping = {{"thousand", 1000}, {"hundred", 100}, {"lakh", 100000}, {"crore", 10000000}};

    long long intA = 0;
    for (char c : A)
    {
        intA = intA * 10 + c - '0';
    }

    long long intB = 0;
    int i = 0;
    for (; i < B.length();)
    {
        bool isMultiplier = false;
        long long currentNumber = 0;
        while (!isMultiplier && i < B.length())
        {
            string currentToken = "";
            while (i < B.length() && B[i] != '-')
            {
                currentToken += B[i];
                i++;
            }
            if (multiplierMapping.find(currentToken) != multiplierMapping.end())
            {
                isMultiplier = true;
                currentNumber *= multiplierMapping[currentToken];
            }
            else
            {
                currentNumber = currentNumber + numberMapping[currentToken];
            }
            if (B[i] == '-')
            {
                i++;
            }
        }
        intB += currentNumber;
    }

    return intA == intB;
}

int main()
{
    // string A = "123456789";
    // string B = "twelve-crore-thirty-four-lakh-fifty-six-thousand-seven-hundred-eighty-nine";
    string A = "18";
    string B = "eighteen-";
    // string A = "1";
    // string B = "one";
    cout << solve(A, B) << endl;
}

// 12,34,56,789