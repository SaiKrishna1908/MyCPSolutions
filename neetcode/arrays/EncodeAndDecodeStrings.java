import java.util.ArrayList;
import java.util.List;

public class EncodeAndDecodeStrings {
    public static String encode(List<String> strs) {        
        StringBuilder sb = new StringBuilder();
        for(String s : strs) {
            for(Character c : s.toCharArray()) {
                sb.append(c+""+c);
            }
            sb.append("01");
        }

        return sb.toString();
    }

    public static List<String> decode(String str) {
        List<String> list = new ArrayList<>();

        String current = "";
        for(int i=1;i<str.length();i+=2) {            
            if (str.charAt(i) == str.charAt(i-1)) {
                current += str.charAt(i);
            } else {
                list.add(current);
                current = "";
            }
        }

        return list;
    }
    public static void main(String[] args) {
        var encodedString =  encode(List.of());
        var list = decode(encodedString);
        System.out.println(encodedString);
        System.out.println(list.toString());
    }
}
