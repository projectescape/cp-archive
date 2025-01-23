vector<int> Solution::spiralOrder(const vector<vector<int>> &A)
{
    vector<int> answer;

    bool isIteratingThroughRow = true;

    bool isRowBeingIncremented = true;
    bool isColBeingIncremented = true;

    int numOfRows = A.size();
    int numOfCol = A[0].size();

    int currCol = 0, currRow = 0;
    bool shouldBreak = false;

    answer.push_back(A[0][0]);

    int iterationNumber = 1;

    while (true)
    {
        if (answer.size() == numOfRows * numOfCol)
        {
            break;
        }
        if (isIteratingThroughRow)
        {
            int unitToAddToCol = isColBeingIncremented ? +1 : -1;
            currCol += unitToAddToCol;
            while ((currCol < numOfCol - (iterationNumber / 4)) && (currCol >= (iterationNumber / 4)))
            {
                answer.push_back(A[currRow][currCol]);
                currCol += unitToAddToCol;
            }
            currCol -= unitToAddToCol;
            isIteratingThroughRow = false;
            isColBeingIncremented = !isColBeingIncremented;
        }
        else
        {
            int unitToAddToRow = isRowBeingIncremented ? +1 : -1;
            currRow += unitToAddToRow;
            while ((currRow < numOfRows - (iterationNumber / 4)) && (currRow >= (iterationNumber / 4)))
            {
                answer.push_back(A[currRow][currCol]);
                currRow += unitToAddToRow;
            }
            currRow -= unitToAddToRow;
            isIteratingThroughRow = true;
            isRowBeingIncremented = !isRowBeingIncremented;
        }
        iterationNumber++;
    }
    return answer;
}