class Solution
{
public:
    int findMin(vector<int> &nums, int start, int end)
    {
        if (start == end)
        {
            return nums[start];
        }

        // Sorted scenario
        if (nums[start] < nums[end])
        {
            return nums[start];
        }

        int mid = (start + end) / 2;

        return min(findMin(nums, start, mid), findMin(nums, mid + 1, end));
    }

    int findMin(vector<int> &nums)
    {
        return findMin(nums, 0, nums.size() - 1);
    }
};
