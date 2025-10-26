import java.util.Stack;

public class MinStack {

    private Stack<Integer> minStack;
    private Stack<Integer> mainStack;

    public MinStack() {
        mainStack = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int val) {
        mainStack.push(val);
        if (minStack.isEmpty() || minStack.peek() > val) {
            minStack.push(val);
        }
    }

    public void pop() {

        var value = mainStack.peek();
        mainStack.pop();
        if (value.equals( minStack.peek())) {
            minStack.pop();
        }

    }

    public int top() {
        return mainStack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }

    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        
        minStack.push(-100);
        minStack.push(-200);
        minStack.push(-300);
        minStack.push(-400);

        System.out.println(minStack.getMin());

        minStack.pop();
        minStack.pop();

        System.out.println(minStack.getMin());
    }
}
