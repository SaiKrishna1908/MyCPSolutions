import java.util.*;

public class GroupAnagrams {

    public static List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        
        for(String s  : strs) {
            char[] carr = s.toCharArray();
            Arrays.sort(carr);
            String sortedString = new String(carr);
            List<String> list = map.getOrDefault(sortedString, new ArrayList<>());
            map.put(sortedString, list);
            list.add(s);
        }

        return map.values().stream().toList();
    }

    public static void main(String[] args) {
        var result =  groupAnagrams(new String[]{"abc", "bac", "bat"});
        for(var l : result) {
            System.out.println(l.toString());
        }
    }
}