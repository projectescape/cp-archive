package NC.java;

import java.util.*;

public class IsAnagram {

    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> sMap = new HashMap<Character, Integer>();
        Map<Character, Integer> tMap = new HashMap<Character, Integer>();

        for (int i = 0; i < s.length(); i++) {
            sMap.put(s.charAt(i), sMap.getOrDefault(s.charAt(i), 0) + 1);
        }

        for (int i = 0; i < t.length(); i++) {
            tMap.put(t.charAt(i), tMap.getOrDefault(t.charAt(i), 0) + 1);
        }

        return sMap.equals(tMap);
    }

    public static void main(String[] args) {
        IsAnagram sol = new IsAnagram();

        System.out.println(sol.isAnagram("racecar", "carrace"));
    }

}
