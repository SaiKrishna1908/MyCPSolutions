import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Anagrams {
    static boolean areAnagrams(String a, String b) {

        if (a == null || b== null) return false;
        if (a.length() != b.length()) return false;

        Map<Character, Integer> freq = new HashMap<>();        

        for(Character c : a.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);            
        }

        for(Character c : b.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) - 1);
        }        

        freq.values().removeIf(t -> t == 0);

        return freq.isEmpty();
    }
    public static void main(String[] args) {
        boolean areAnagrams = areAnagrams("abb", "bba");
        System.out.println(areAnagrams);
    }
}