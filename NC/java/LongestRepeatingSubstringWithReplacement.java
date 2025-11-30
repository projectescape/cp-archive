package NC.java;

import java.util.HashMap;
import java.util.Map;

public class LongestRepeatingSubstringWithReplacement {
    private char getMaxChar(Map<Character, Integer> charCount) {
        char ans = 'a';

        for (var pair : charCount.entrySet()) {
            if (pair.getValue() > charCount.getOrDefault(ans, 0)) {
                ans = pair.getKey();
            }
        }

        return ans;
    }

    public int characterReplacement(String s, int k) {

        if (s.length() == 0) {
            return 0;
        }

        Map<Character, Integer> charCount = new HashMap();

        charCount.put(s.charAt(0), 1);

        int ans = 1;

        for (int i = 0, j = 1; j < s.length(); j++) {
            char rightChar = s.charAt(j);
            charCount.put(rightChar, charCount.getOrDefault(rightChar, 0) + 1);

            while (j - i + 1 - charCount.get(this.getMaxChar(charCount)) > k) {
                char leftChar = s.charAt(i);
                charCount.put(leftChar, charCount.get(leftChar) - 1);
                i++;
            }

            ans = Math.max(ans, j - i + 1);

        }

        return ans;
    }
}
