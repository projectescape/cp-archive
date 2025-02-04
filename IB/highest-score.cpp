int Solution::highestScore(vector<vector<string>> &A)
{
    unordered_map<string, vector<int>> marks;

    for (vector<string> pair : A)
    {
        int currentMarks = 0;
        for (char c : pair[1])
        {
            currentMarks = currentMarks * 10 + c - '0';
        }
        marks[pair[0]].push_back(currentMarks);
    }
    int answer = INT_MIN;
    for (auto it : marks)
    {
        long totalMarks = 0;
        for (int i : it.second)
        {
            totalMarks += i;
        }
        answer = max(answer, (int)(totalMarks / (it.second.size())));
    }
    return answer;
}
