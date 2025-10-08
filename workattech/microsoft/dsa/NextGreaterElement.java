import java.util.Arrays;
import java.util.Stack;

public class NextGreaterElement {

    static int[] getNextGreaterElements(int a[]) {
        Stack<Integer> stack = new Stack<>();

        int res[] = new int[a.length];

        Arrays.fill(res, -1);

        for(int i=a.length-1;i>=0;i--) {
            
            while(!stack.empty() && stack.peek() <= a[i]) {
                stack.pop();
            }

            if (!stack.empty()) {
                res[i] = stack.peek();
            }

            stack.push(a[i]);
        }

        return res;
    }

    public static void main(String[] args) {
        runTest(new int[]{4,5,2,10,8}, new int[]{5,10,10,-1,-1});
        runTest(new int[]{1,3,2,4},    new int[]{3,4,4,-1});
        runTest(new int[]{6,8,0,1,3},  new int[]{8,-1,1,3,-1});
        runTest(new int[]{1,1,1},      new int[]{-1,-1,-1});
        runTest(new int[]{9},          new int[]{-1});
        runTest(new int[]{},           new int[]{}); // empty   
    }

    private static void runTest(int[] input, int[] expected) {
        int[] actual = getNextGreaterElements(input);
        System.out.println(Arrays.toString(input) + " -> " + Arrays.toString(actual)
            + " (expected " + Arrays.toString(expected) + ") "
            + (Arrays.equals(actual, expected) ? "OK" : "FAIL"));
    }
}