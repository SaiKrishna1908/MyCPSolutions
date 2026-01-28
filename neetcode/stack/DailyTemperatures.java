import java.util.Arrays;
import java.util.Stack;

public class DailyTemperatures {

    private static class Pair<K extends Comparable<K>, V> implements Comparable<Pair<K, V>> {
        private K key;
        private V value;

        public Pair(K k, V v) {
            this.key = k;
            this.value = v;
        }

        @Override
        public int compareTo(Pair<K, V> o) {
            return this.key.compareTo(o.key);
        }

        public K getKey() {
            return this.key;
        }

        public V getValue() {
            return this.value;
        }
    }

    public static int[] dailyTemperatures(int[] temperatures) {
        Stack<Pair<Integer, Integer>> stack = new Stack<>();

        int[] results = new int[temperatures.length];

        for (int i = temperatures.length - 1; i >= 0; i--) {

            while (!stack.isEmpty() && stack.peek().getKey() < temperatures[i]) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                results[i] = 0;
            } else {
                results[i] = stack.peek().getValue() - i;                
            }
            stack.push(new Pair<Integer,Integer>(temperatures[i], i));
        }

        return results;
    }

    public static void main(String[] args) {
       System.out.println(Arrays.toString(dailyTemperatures(new int[]{30,38,30,36,35,40,28})));
    }
}
