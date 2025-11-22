class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> maxHeightToRight(height.size(), 0);
        vector<int> maxHeightToLeft(height.size(), 0);

        int maxHeight = 0;
        for (int i = 0; i < height.size(); i++)
        {
            maxHeightToLeft[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }
        maxHeight = 0;
        for (int i = height.size() - 1; i >= 0; i--)
        {
            maxHeightToRight[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }

        int ans = 0;

        for (int i = 0; i < height.size(); i++)
        {
            ans += max(0, min(maxHeightToLeft[i], maxHeightToRight[i]) - height[i]);
        }

        return ans;
    }
};
