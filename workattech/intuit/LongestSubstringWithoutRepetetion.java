import java.util.HashMap;
import java.util.Map;

public class LongestSubstringWithoutRepetetion {

    private int getLongestSubstringWithoutRepeteation(String s) {
        int max=1;

        Map<Character, Integer> map = new HashMap<>();
        
        int left = 0;        

        for(int right =0;right<s.length();right++) {            
            Character curChar = s.charAt(right);
            if (map.containsKey(curChar)) {
            // We already saw a character    
                left = Math.max(left, map.get(curChar) + 1);                
            }
            map.put(curChar, right);
            max = Math.max(max, right - left + 1);
        }

        return max;
    }

    public static void main(String[] args) {
        
    }
}