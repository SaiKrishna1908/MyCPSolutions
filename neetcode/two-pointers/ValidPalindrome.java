public class ValidPalindrome {
    private static String sanitize(String s) {
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length();i++) {
            int ascii = (int)  (Character.toLowerCase(s.charAt(i)) - 'a');
            System.out.println(ascii);
            if (Character.isDigit(s.charAt(i)) ||  ascii >= 0 && ascii <= 26) {
                sb.append(Character.toLowerCase( s.charAt(i)));
            }
        }
        return sb.toString();
    }
    private static boolean isPalindrome(String s) {        
        s = sanitize(s);

        int low = 0;
        int high = s.length()-1;        
        System.out.println(s);
        for(;low<high;low++,high--) {
            if (s.charAt(low) != s.charAt(high)) {
                return false;
            }
        }

        return true;
    }
    public static void main(String[] args) {
        System.out.println(isPalindrome("0P"));
    }
}
