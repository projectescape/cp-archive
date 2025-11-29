package NC.java;

import java.util.ArrayList;
import java.util.List;

public class StringEncodeAndDecode {

    public String encode(List<String> strs) {
        StringBuilder ans = new StringBuilder();

        for (var s : strs) {
            ans.append(Integer.toString(s.length()));
            ans.append("#");
            ans.append(s);
        }

        return ans.toString();

    }

    public List<String> decode(String str) {

        StringBuilder curr = new StringBuilder();
        List<String> ans = new ArrayList();

        for (int i = 0; i < str.length();) {
            curr = new StringBuilder();
            char currChar = str.charAt(i);
            while (currChar != '#') {
                curr.append(currChar);
                i++;
                currChar = str.charAt(i);
            }
            int length = Integer.parseInt(curr.toString());
            i++;

            ans.add(str.substring(i, i + length));
            i = i + length;
        }

        return ans;

    }

}
