import java.util.*;

class TwoSum {
	int[] twoSum(int[] A, int target) {
	    
		
		Map<Integer, List<Integer>> posMap = new HashMap<>();
		
		for(int i=0;i<A.length;i++) {
			if (posMap.containsKey(A[i])) {
				posMap.get(A[i]).add(i);				
			} else {
				List<Integer> newList = new ArrayList<>();
				newList.add(i);
				posMap.put(A[i], newList);
			}
		}
		
		Arrays.sort(A);
		
		int left = 0;
		int right = A.length-1;
		
		int[] result = new int[2];
		
		while (left < right) {
			int currentSum = A[left] + A[right];
			
			if (currentSum > target) {
				right--;
			} else if (currentSum < target) {
				left++;
			} else {
				if (A[left] == A[right]) {
					result[0] = posMap.get(A[left]).get(0);
					result[1] = posMap.get(A[right]).get(1);
					return result;
				} else {
					result[0] = posMap.get(A[left]).get(0);
					result[1] = posMap.get(A[right]).get(0);
					return result;
				}
			}
		}
		
		return result;
	}

	public static void main(String[] args) {
		TwoSum solution = new TwoSum();
		System.out.println(solution.twoSum(new int[]{2,7,11,15}, 9));

	}
}