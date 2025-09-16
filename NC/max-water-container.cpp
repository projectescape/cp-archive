class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int ans = 0;
        for (int i = 0, j = heights.size() - 1; i < j;)
        {
            ans = max((j - i) * min(heights[i], heights[j]), ans);
            if (heights[i] < heights[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};
