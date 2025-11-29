package NC.java;

public class ProductsOfArrayDiscludingSelf {
    public int[] productExceptSelf(int[] nums) {
        int zeroCount = 0;
        int totalProduct = 1;

        for (var num : nums) {
            if (num == 0) {
                zeroCount++;
            } else {
                totalProduct *= num;
            }
        }

        int[] ans = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            int curr = nums[i];
            if (zeroCount > 1) {
                ans[i] = 0;
            } else if (zeroCount == 1 && curr != 0) {
                ans[i] = 0;
            } else if (zeroCount == 1 && curr == 0) {
                ans[i] = totalProduct;
            } else {
                ans[i] = totalProduct / curr;
            }
        }

        return ans;
    }
}
