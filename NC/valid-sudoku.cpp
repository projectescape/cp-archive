class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            set<char> nums;
            for (int j = 0; j < board.size(); j++)
            {
                char curr = board[i][j];
                if (curr != '.')
                {
                    if (nums.find(curr) != nums.end())
                    {
                        return false;
                    }
                    nums.insert(curr);
                }
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            set<char> nums;
            for (int j = 0; j < board.size(); j++)
            {
                char curr = board[j][i];
                if (curr != '.')
                {
                    if (nums.find(curr) != nums.end())
                    {
                        return false;
                    }
                    nums.insert(curr);
                }
            }
        }

        for (int a = 0; a < 3; a++)
        {
            for (int b = 0; b < 3; b++)
            {
                set<char> nums;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        char curr = board[a * 3 + i][b * 3 + j];
                        if (curr != '.')
                        {
                            if (nums.find(curr) != nums.end())
                            {

                                return false;
                            }
                            nums.insert(curr);
                        }
                    }
                }
            }
        }
        return true;
    }
};
