import java.util.Arrays;

public class ProductOfArrayExceptSelf {
    public static int[] productExceptSelf(int[] nums) {

        int n = nums.length;
        int[] prefixProduct = new int[nums.length];
        int[] suffixProduct = new int[nums.length];

        prefixProduct[0] = 1;
        for(int i=1;i<n;i++) {
            prefixProduct[i] = nums[i-1] * prefixProduct[i-1];
        }

        suffixProduct[n-1] = 1;
        for(int i=n-2;i>=0;i--) {
            suffixProduct[i] = suffixProduct[i+1] * nums[i+1];
        }

        int[] res = new int[n];

        for(int i=0;i<n;i++) {
            res[i] = prefixProduct[i] * suffixProduct[i];
        }

        return res;
    }

    public static void main(String[] args) {
        var result = productExceptSelf(new int[]{1,2,4,6});        
        System.out.println(Arrays.toString(result) + "");
    }
}
