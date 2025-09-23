import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class PancakeSort {    

    // flip the arr from i to k
    static void flip(int[] arr, int k) {
        int[] copyArray = Arrays.copyOfRange(arr, 0, k);
        List<Integer> copyArrayList = Arrays.stream(copyArray).boxed().collect(Collectors.toList());
        Collections.reverse(copyArrayList);   
        
        for(int i=0;i<k;i++) {
            arr[i] = copyArrayList.get(i);
        }
    }

    static void pancakeSort(int[] arr) {        
        int n = arr.length;

        PriorityQueue<Integer> pairs = new PriorityQueue<>(( o1,  o2) -> Integer.compare(o2, o1));
        for(int i=0;i<arr.length;i++) {
            pairs.add(arr[i]);
        }

        int currentWinSize = n-1;

        List<Integer> list = new ArrayList<>();


        while(!pairs.isEmpty()) {
            Integer currentHighest = pairs.poll();
            // check if the current element is at the correct position
            List<Integer> l = Arrays.stream(arr).boxed().collect(Collectors.toList());
            Integer index = l.indexOf(currentHighest);
            

            if (index != currentWinSize) {
                list.add(index+1);
                flip(arr, index+1);
                list.add(currentHighest+1);
                flip(arr, currentWinSize+1);
            }            

            currentWinSize--;
        }   
    }

    public static void main(String[] args) {
        int[] arr = new int[]{3,4,2,1};
        pancakeSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
