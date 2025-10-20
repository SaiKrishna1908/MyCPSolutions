import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

// [-4,-1,-1,0,1,2]
public class ThreeSum {

    private static List<List<Integer>> threeSum(int[] nums) {
        Map<Integer, List<List<Integer>>> map = new HashMap<>();        
        for(int i=0;i<nums.length;i++) {
            for(int j=i+1;j<nums.length;j++) {
                int sum = nums[i] + nums[j];
                if (map.containsKey(sum)) {
                    map.get(sum).add(List.of(i,j));
                } else {
                    List<List<Integer>> tempList = new ArrayList<>();
                    tempList.add(List.of(i,j));
                    map.put(sum, tempList);
                }
                
            }
        }

        Set<List<Integer>> result = new HashSet<>();

        for(int i=0;i<nums.length;i++) {
            int needed = -1 * (nums[i]);
            if (map.containsKey(needed)) {
                List<List<Integer>> possibleSums = map.get(needed);                
                for(int k=0;k<possibleSums.size();k++) {
                    if (!possibleSums.get(k).contains(i)) {
                        List<Integer> possibleSolution = new ArrayList<>();
                        possibleSolution.add(nums[i]);
                        possibleSolution.add(nums[possibleSums.get(k).get(0)]);
                        possibleSolution.add(nums[possibleSums.get(k).get(1)]);
                        Collections.sort(possibleSolution);
                        result.add(possibleSolution);
                    }                    
                }                
            }
        }
        
        List<List<Integer>> solution = new ArrayList<>(result);
        return solution;
    }
    public static void main(String[] args) {
        var solution = threeSum(new int[]{-1,0,1,2,-1,-4,-2,-3,3,0,4});
        System.out.println(solution);
    }
}
