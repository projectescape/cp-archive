class Solution
{
public:
    int search(vector<int> &nums, int target, int start, int end)
    {

        if (start > end)
        {
            return -1;
        }

        if (start + 1 == end)
        {
            if (nums[start] == target)
            {
                return start;
            }
            else if (nums[end] == target)
            {
                return end;
            }
        }

        if (start == end)
        {
            if (nums[start] == target)
            {
                return start;
            }
            else
            {
                return -1;
            }
        }

        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[start] < nums[end])
        {
            if (nums[mid] < target)
            {
                return search(nums, target, mid + 1, end);
            }
            else
            {
                return search(nums, target, start, mid - 1);
            }
        }

        if (nums[start] < nums[mid])
        {
            // Left is sorted, right is not

            if (target >= nums[start] && target < nums[mid])
            {
                return search(nums, target, start, mid - 1);
            }
            return search(nums, target, mid + 1, end);
        }
        else
        {
            // Left is not sorted, right is
            if (target > nums[mid] && target <= nums[end])
            {
                return search(nums, target, mid + 1, end);
            }
            return search(nums, target, start, mid - 1);
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        return search(nums, target, 0, nums.size() - 1);
    }
};
