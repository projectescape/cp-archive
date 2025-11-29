package NC.java;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeIntegerSum {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList();

        for (int i = 0; i < nums.length; i++) {
            int curr = nums[i];
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            if (curr > 0) {
                break;
            }
            int j = i + 1, k = nums.length - 1;

            while (j < k) {
                int sum = curr + nums[j] + nums[k];
                if (sum == 0) {
                    ans.add(List.of(curr, nums[j], nums[k]));
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
}
