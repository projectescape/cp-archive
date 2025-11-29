package NC.java;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class LongestConsecutiveSequence {

    public int longestConsecutive(int[] nums) {
        Set<Integer> numSet = new HashSet();
        Set<Integer> visited = new HashSet();

        for (int num : nums) {
            numSet.add(num);
        }

        int ans = 0;

        for (int num : nums) {
            if (visited.contains(num)) {
                continue;
            } else {
                visited.add(num);
            }
            int lowest = num;
            while (numSet.contains(lowest - 1)) {
                lowest--;
                visited.add(lowest);
            }
            int highest = num;
            while (numSet.contains(highest + 1)) {
                highest++;
                visited.add(highest);
            }
            ans = Math.max(ans, highest - lowest + 1);
        }

        return ans;

    }
}
