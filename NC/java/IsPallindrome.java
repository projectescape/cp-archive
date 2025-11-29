package NC.java;

public class IsPallindrome {

    public boolean isPalindrome(String s) {

        s = s.toLowerCase();

        for (int i = 0, j = s.length() - 1; i < j;) {
            char left = s.charAt(i);
            if (!((left >= 'a' && left <= 'z') || (left >= '0' && left <= '0'))) {
                i++;
                continue;
            }
            char right = s.charAt(j);
            if (!((right >= 'a' && right <= 'z') || (right >= '0' && right <= '9'))) {
                j--;
                continue;
            }

            if (left != right) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

}
