import java.util.HashSet;
import java.util.Set;

public class LongestConsecutiveSequence {
    public static int longestConsecutive(int[] nums) {        
        Set<Integer> set = new HashSet<Integer>();
        for(int i=0;i<nums.length;i++) {
            set.add(nums[i]);
        }

        int max = 0;

        for(int num : nums) {
            int curr = num;
            int streak = 0;
            while(set.contains(curr++)) {
                streak++;
            }

            max = Math.max(streak, max);
        }

        return max;
    }
    public static void main(String[] args) {
        System.out.println(longestConsecutive(new int[]{2,20,4,10,3,4,5}));
    }
    
}
