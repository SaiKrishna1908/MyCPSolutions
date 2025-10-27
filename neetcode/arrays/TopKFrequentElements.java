import java.util.*;

public class TopKFrequentElements {
    private static class Pair<K,V> {
        K key;
        V value;

        @Override
        public boolean equals(Object obj) {
            Pair other = (Pair<K,V>) obj;
            return this.key == other.key && value == other.value;
        }
    }

    public static int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        for(int i=0;i<nums.length;i++) {            
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }

        List<Integer> result = new ArrayList<>();
        map.entrySet().stream().sorted(Map.Entry.comparingByValue((o1, o2) -> Integer.compare(o2, o1))).forEach(t -> {
            if (result.size() < k) {
                result.add(t.getKey());
            }
        });

        return result.stream().mapToInt(i -> i).toArray();
    }
    
    public static void main(String[] args) {
        int[] result = topKFrequent(new int[]{1,2,2,3,3,3}, 2);

        for(int i : result) {
            System.out.println(i);
        }
    }
}
