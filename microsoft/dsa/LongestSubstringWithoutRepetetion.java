public class LongestSubstringWithoutRepetetion {
    int getLongestSubstringWithoutRepeat(String s) {
        int n = s.length();        
        int max = 0;

        int low = 0;
        int high = 0;

        boolean visited[] = new boolean[n];

        while(high < n) {
            
            while(visited[s.charAt(high) - 'a'] == true) {
                visited[s.charAt(low) - 'a'] = false;
                low++;
            }

            visited[s.charAt(high) - 'a'] = true;
            max = Math.max(high - low + 1, max);
            high++;
        }

        return max;
    }

    // ...existing code...
    public static void main(String[] args) {
        LongestSubstringWithoutRepetetion s = new LongestSubstringWithoutRepetetion();
        runTest(s, "", 0);
        runTest(s, "a", 1);
        runTest(s, "bbbbb", 1);
        runTest(s, "abcabcbb", 3);
        runTest(s, "abcdef", 6);
        runTest(s, "aab", 2);
        runTest(s, "abcaef", 5);
        runTest(s, "abcddef", 4);
        runTest(s, "abababab", 2);
        runTest(s, "abcdeafgh", 8);
    }

    private static void runTest(LongestSubstringWithoutRepetetion s, String input, int expected) {
        int actual = s.getLongestSubstringWithoutRepeat(input);
        System.out.println("\"" + input + "\" -> " + actual + " (expected " + expected + ") "
                + (actual == expected ? "OK" : "FAIL"));
    }
}
