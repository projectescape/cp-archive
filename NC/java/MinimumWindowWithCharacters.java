package NC.java;

import java.util.HashMap;
import java.util.Map;

public class MinimumWindowWithCharacters {
    private boolean isValidSubString(Map<Character, Integer> sMap, Map<Character, Integer> tMap) {
        for (var entry : tMap.entrySet()) {
            if (sMap.getOrDefault(entry.getKey(), 0) < entry.getValue()) {
                return false;
            }
        }

        return true;
    }

    public String minWindow(String s, String t) {
        if (s.equals("") || t.equals("")) {
            return "";
        }

        if (s.length() == 1 && s.equals(t)) {
            return s;
        }

        Map<Character, Integer> tMap = new HashMap();
        Map<Character, Integer> sMap = new HashMap();

        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            tMap.put(c, tMap.getOrDefault(c, 0) + 1);
        }

        boolean answerExists = false;

        String ans = s;

        for (int i = 0, j = 0; j < s.length(); j++) {
            char rightChar = s.charAt(j);
            sMap.put(rightChar, sMap.getOrDefault(rightChar, 0) + 1);

            if (isValidSubString(sMap, tMap)) {
                answerExists = true;
                char leftChar = s.charAt(i);
                while (sMap.get(leftChar) - 1 >= tMap.getOrDefault(leftChar, 0)) {
                    sMap.put(leftChar, sMap.get(leftChar) - 1);
                    i++;
                    leftChar = s.charAt(i);
                }
                if (ans.length() > j - i + 1) {
                    ans = s.substring(i, j + 1);
                }
                sMap.put(s.charAt(i), sMap.get(s.charAt(i)) - 1);
                i++;
            }
        }

        if (!answerExists) {
            return "";
        }

        return ans;

    }
}
