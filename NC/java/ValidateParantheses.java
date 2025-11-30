package NC.java;

import java.util.Map;
import java.util.Stack;

public class ValidateParantheses {

    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        Map<Character, Character> bracketMap = Map.of(']', '[', '}', '{', ')', '(');

        for (char c : s.toCharArray()) {
            if (bracketMap.keySet().contains(c)) {
                if (stack.size() == 0) {
                    return false;
                }
                if (!stack.peek().equals(bracketMap.get(c))) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        return stack.size() == 0;

    }

}
