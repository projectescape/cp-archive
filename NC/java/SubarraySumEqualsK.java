package NC.java;

import java.util.HashMap;
import java.util.Map;

public class SubarraySumEqualsK {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> prefixSum = new HashMap<>();
        int curr = 0;
        int ans = 0;

        prefixSum.put(0, 1);
        for (int num : nums) {
            curr += num;
            int required = curr - k;

            ans += prefixSum.getOrDefault(required, 0);
            prefixSum.merge(curr, 1, (old, newVal) -> old + newVal);
        }

        return ans;
    }
}
