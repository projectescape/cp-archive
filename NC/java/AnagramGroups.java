package NC.java;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class AnagramGroups {

    private String generatePrefix(Map<Character, Integer> currMap) {
        StringBuilder s = new StringBuilder();

        for (char c = 'a'; c <= 'z'; c++) {
            s.append("#");
            s.append(c);
            s.append(":");
            s.append(currMap.getOrDefault(c, 0).toString());
        }
        return s.toString();
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, Map<Character, Integer>> countMap = new HashMap();

        for (int i = 0; i < strs.length; i++) {
            String curr = strs[i];

            Map<Character, Integer> m = new HashMap();

            for (int j = 0; j < curr.length(); j++) {
                m.put(curr.charAt(j), m.getOrDefault(curr.charAt(j), 0) + 1);
            }
            countMap.put(curr, m);
        }

        Map<String, List<String>> ansMap = new HashMap();

        for (var key : strs) {
            Map currMap = countMap.get(key);
            String prefix = this.generatePrefix(currMap);

            if (!ansMap.containsKey(prefix)) {
                ansMap.put(prefix, new ArrayList());
            }

            ansMap.get(prefix).add(key);
        }

        List<List<String>> ans = new ArrayList();

        for (List<String> list : ansMap.values()) {
            ans.add(list);
        }
        return ans;

    }

}
