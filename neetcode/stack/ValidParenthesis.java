import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class ValidParenthesis {
    private boolean isOpen(Character character) {
        List<Character> charList = List.of('(', '{', '[');

        return charList.contains(character);
    }
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();        

        Map<Character, Character> pairMap = new HashMap<>();

        pairMap.put(')', '(');
        pairMap.put('}', '{');
        pairMap.put(']', '[');

        for(int i=0;i<s.length();i++) {
            Character currentChar = s.toCharArray()[i];
            if (isOpen(currentChar)) {
                stack.push(currentChar);
            } else {                
                if (stack.empty()) {
                    return false;
                }

                if(stack.peek() != pairMap.get(currentChar)) {         
                    return false;
                } else {
                    stack.pop();
                }                
            }
        }

        return stack.isEmpty();
    }
    public static void main(String[] args) {
        ValidParenthesis validParenthesis = new ValidParenthesis();
        System.out.println( validParenthesis.isValid("{}"));
    }
}