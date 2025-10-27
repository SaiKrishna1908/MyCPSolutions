import java.util.List;
import java.util.Stack;

public class EvaluateReversePolishNotation {
    List<Character> operators = List.of('+','-','*','/');
    private boolean isOperator(Character c) {
        return operators.contains(c);
    }

    private int operation(String a, String b, Character op) {
        int parsedA = Integer.parseInt(a);
        int parsedB = Integer.parseInt(b);
        switch (op) {
            case '+':
                return parsedA + parsedB;                
            case '-':
                return parsedA - parsedB;
            case '*':
                return parsedA * parsedB;
            case '/':
                return parsedA / parsedB;        
            default:
                throw new RuntimeException("Unsupported Operation");
        }                
    }
    public int evalRPN(String[] tokens) {
        Stack<String> stack = new Stack<>();        
        for(int i=0;i<tokens.length;i++) {
            if (tokens[i].length() == 1 && isOperator(tokens[i].toCharArray()[0])) {
                String b = stack.pop();
                String a = stack.pop();
                int result =  operation(a, b, tokens[i].toCharArray()[0]);
                stack.push(Integer.toString(result));
            } else {
                stack.push(tokens[i]);
            }
        }

        return Integer.parseInt(stack.peek());
    }
    public static void main(String[] args) {
        EvaluateReversePolishNotation evaluateReversePolishNotation = new EvaluateReversePolishNotation();
        System.out.println(evaluateReversePolishNotation.evalRPN(new String[]{"1","2","+","3","*","4","-"}));

    }
}
