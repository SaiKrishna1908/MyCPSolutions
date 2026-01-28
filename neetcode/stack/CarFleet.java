import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Stack;

public class CarFleet {
    private static class Pair implements Comparable {
        Integer position;
        Integer speed;

        public Pair(int position, int speed) {
            this.position = position;
            this.speed = speed;
        }

        @Override
        public int compareTo(Object other) {
            Pair otherPair = (Pair) other;
            return this.position.compareTo(otherPair.position);
        }

        @Override
        public String toString() {
            return "position: " + this.position + " speed: "+ speed;
        }
    }
    public int carFleet(int target, int[] position, int[] speed) {
        List<Pair> positionPair = new ArrayList<>();
        for(int i=0;i<position.length;i++) {
            positionPair.add(new Pair(position[i], speed[i]));
        }

        Collections.sort(positionPair, Comparator.reverseOrder());        

        Stack<Integer> stack = new Stack<>();

        for(int i=0;i<positionPair.size();i++) {
            int time = (target - positionPair.get(i).position)/positionPair.get(i).speed;

            if (stack.isEmpty()) {
                stack.push(time);
            } else {
                if (time > stack.peek()) {
                    stack.push(time);
                }
            }
        }

        return stack.size();
    }

    public static void main(String[] args) {
        CarFleet carFleet = new CarFleet();

        int result = carFleet.carFleet(10, new int[]{6,8}, new int[]{3,2});
        System.out.println(result);
    }
}
