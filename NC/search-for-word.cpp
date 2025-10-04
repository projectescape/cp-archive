class Solution
{
public:
    bool traverseAndFindIfExists(vector<vector<char>> &board,
                                 vector<vector<int>> &traversed,
                                 string &word,
                                 int i, int j, int index)
    {
        if (index == word.size())
        {
            return true;
        }

        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || traversed[i][j] == 1 || board[i][j] != word[index])
        {
            return false;
        }

        traversed[i][j] = 1;

        if (
            traverseAndFindIfExists(
                board,
                traversed,
                word,
                i + 1,
                j,
                index + 1) ||
            traverseAndFindIfExists(
                board,
                traversed,
                word,
                i,
                j + 1,
                index + 1) ||
            traverseAndFindIfExists(
                board,
                traversed,
                word,
                i - 1,
                j,
                index + 1) ||
            traverseAndFindIfExists(
                board,
                traversed,
                word,
                i,
                j - 1,
                index + 1))
        {
            return true;
        }
        traversed[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        if (word.size() == 0)
        {
            return true;
        }

        vector<vector<int>> traversed(board.size(), vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[0] == board[i][j] && traverseAndFindIfExists(
                                                  board, traversed, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
