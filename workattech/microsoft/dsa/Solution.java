import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    static void printHashMap(Map<Integer, Integer> map) {
        for(Integer key : map.keySet()) {
            System.out.println("Key: " + key+ " value: "+ map.get(key));
        }
        System.out.println("####");
    }
	static int[] distintNumbersInWindow(int[] A, int k) {
		Map<Integer,Integer> map = new HashMap<Integer, Integer>();
		
		List<Integer> list = new ArrayList<>();
		
		for(int i=0;i<k;i++) {
			if (map.containsKey(A[i])) {         
				map.put(A[i], map.get(A[i]) + 1);
			} else {
                map.put(A[i],1);
            }			
		}
		
		list.add(map.size());

        printHashMap(map);
		
		for(int i=k;i<A.length;i++) {
			int toRemoveIdx = i - k;            
			if (map.get(A[toRemoveIdx]) == 1) {
				map.remove(A[toRemoveIdx]);
			} else {
				map.put(A[toRemoveIdx], map.get(A[toRemoveIdx])-1 );
			}
			if (map.containsKey(A[i])) {
				map.put(A[i], map.get(A[i]) + 1);
			} else {
				map.put(A[i], 1);
			}
			
            printHashMap(map);
			list.add(map.size());
		}
		
		int res[] = new int[list.size()];
		
		for(int i=0;i<list.size();i++) {
			res[i] = list.get(i);
		}
		
		return res;
	}

    public static void main(String[] args) {
        int[] A= new int[]{1,1,2,1,1};
        int k = 2;
        System.out.println(Arrays.toString(distintNumbersInWindow(A,k))); 
    }
}
