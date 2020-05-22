// Much better solution using dp
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/441306/JavaC%2B%2BPython-DP-solution

void boxes(vector<vector<int>> &matrix, int &i, int &j, int &m, int &n, int &ans) {
    ans++;
    for (int a = i + 1, b = j + 1, temp; a < m && b < n; ++a, ++b) {
        for (temp = i; temp <= a; temp++) {
            if (!matrix[temp][b]) return;
        }
        for (temp = j; temp <= b; temp++) {
            if (!matrix[a][temp]) return;
        }
        ans++;
    }

    return;
}

class Solution {
   public:
    int countSquares(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j])
                    boxes(matrix, i, j, m, n, ans);
        return ans;
    }
};