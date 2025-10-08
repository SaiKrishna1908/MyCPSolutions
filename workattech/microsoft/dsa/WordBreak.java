import java.util.Map;
import java.util.HashMap;

public class WordBreak {
    /**
     * 1. How many states in my dp ?
     * We will be having one state in our dp
     * 
     * 2. What does each state represent ?
     * dp[i] -> can we create a string[0..i] using words[]
     * 
     * 3. What would be my transition ?
     * dp[i] -> dp[0..j] == true && dp[j..i] in words
     * 
     * @param s
     * @param w
     * @return
     */
    static boolean wordBreak(String s, String[] w) {
        Map<String, Integer> map = new HashMap<>();

        for(String string : w) {
            map.put(string, 1);
        }

        boolean dp[] = new boolean[s.length() + 1];
        dp[0] = true;

        for(int i=1;i<dp.length;i++) {
            for(int j=0;j<i;j++) {                
                if (dp[j] && map.containsKey(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
    public static void main(String[] args) {
        String s = "roundandround";
        String words[] = new String[]{"and", "round"};

        System.out.println(wordBreak(s, words));
        
    }
}
