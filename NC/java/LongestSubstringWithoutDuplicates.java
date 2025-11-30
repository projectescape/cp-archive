package NC.java;

import java.util.HashMap;
import java.util.Map;

public class LongestSubstringWithoutDuplicates {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }

        int ans = 1;
        Map<Character, Integer> charCount = new HashMap<>();
        charCount.put(s.charAt(0), 1);

        for (int i = 0, j = 1; j < s.length(); j++) {
            char currChar = s.charAt(j);
            charCount.put(currChar, charCount.getOrDefault(currChar, 0) + 1);

            while (charCount.get(currChar) > 1) {
                Character toBeRemoved = s.charAt(i);
                charCount.put(toBeRemoved, charCount.get(toBeRemoved) - 1);
                i++;
            }

            ans = Math.max(ans, j - i + 1);

        }

        return ans;

    }
}
