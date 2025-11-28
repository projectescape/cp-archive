package NC.java;

import java.util.*;

public class TwoIntegerSum {

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, List<Integer>> numberToIndex = new HashMap();

        for (int i = 0; i < nums.length; i++) {
            if (!numberToIndex.containsKey(nums[i])) {
                numberToIndex.put(nums[i], new ArrayList());
            }
            numberToIndex.get(nums[i]).add(i);
        }

        for (int i = 0; i < nums.length; i++) {
            int subTarget = target - nums[i];
            if (numberToIndex.containsKey(subTarget)) {
                List<Integer> indexList = numberToIndex.get(subTarget);
                if (i == indexList.get(0)) {
                    if (indexList.size() > 1) {
                        return new int[] { i, indexList.get(1) };
                    }
                } else {
                    return new int[] { i, indexList.get(0) };
                }
            }
        }

        return new int[] {};
    }

    public static void main(String[] args) {
        TwoIntegerSum sol = new TwoIntegerSum();

        System.out.println(sol.twoSum(new int[] { 1, 3, 4, 2 }, 6));
    }

}
