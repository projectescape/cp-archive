package NC.java;

public class FindMinimumInRotatedSortedArray {
    private int findMin(int[] nums, int leftIndex, int rightIndex) {
        int midIndex = (leftIndex + rightIndex) / 2;
        int left = nums[leftIndex], right = nums[rightIndex], mid = nums[midIndex];

        if (leftIndex == rightIndex) {
            return left;
        }

        if (left > mid) {
            return findMin(nums, leftIndex + 1, midIndex);
        }

        if (mid > right) {
            return findMin(nums, midIndex + 1, rightIndex);
        }

        return left;

    }

    public int findMin(int[] nums) {
        return findMin(nums, 0, nums.length - 1);
    }
}
