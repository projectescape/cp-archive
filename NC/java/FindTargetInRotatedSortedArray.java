package NC.java;

public class FindTargetInRotatedSortedArray {
    public int search(int[] nums, int target, int leftIndex, int rightIndex) {

        if (leftIndex > rightIndex) {
            return -1;
        }

        if (leftIndex == rightIndex) {
            if (nums[leftIndex] == target) {
                return leftIndex;
            } else {
                return -1;
            }
        }

        int midIndex = (leftIndex + rightIndex) / 2;

        int left = nums[leftIndex], right = nums[rightIndex], mid = nums[midIndex];

        if (target == mid) {
            return midIndex;
        } else if (target < mid) {
            if ((left <= target) || (left > mid)) {
                return search(nums, target, leftIndex, midIndex - 1);
            } else {
                return search(nums, target, midIndex + 1, rightIndex);
            }
        } else {
            if (right >= target || right < mid) {
                return search(nums, target, midIndex + 1, rightIndex);
            } else {
                return search(nums, target, leftIndex, midIndex - 1);
            }
        }

    }

    public int search(int[] nums, int target) {
        return search(nums, target, 0, nums.length - 1);
    }
}
