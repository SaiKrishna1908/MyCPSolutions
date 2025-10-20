import java.util.Arrays;

public class TwoSumII {
    public static int[] twoSum(int[] numbers, int target) {
        int low = 0;
        int high = numbers.length-1;

        while(low < high) {
            int current = numbers[low] + numbers[high];
            if (current < target) {
                low++;
            } else if (current > target) {
                high--;
            } else {
                return new int[]{low+1, high+1};
            }
        }

        return new int[]{-1, -1};
    }
    public static void main(String[] args) {
        System.out.println(Arrays.toString( twoSum(new int[]{1,2,3,4}, 3)));
    }
}
