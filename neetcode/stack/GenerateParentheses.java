import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class GenerateParentheses {

    private void dfs(int l, int r, String t, List<String> acc, int n) {
        if (l < r) {
            return;
        }
        if (l == n && r == n) {
            acc.add(t);
            return;
        }

        if (l < n) {
            dfs(l+1,r,t+"(",acc, n);
        }

        if (r < n) {
            dfs(l, r+1, t+")", acc, n);
        }
    }

    public List<String> generateParenthesis(int n) {
        List<String> accumulator = new ArrayList<>();
        dfs(0, 0, "", accumulator, n);

        return accumulator;
    }
    public static void main(String[] args) {
        GenerateParentheses generateParentheses = new GenerateParentheses();

        var result = generateParentheses.generateParenthesis(3);
        for(String s : result) {
            System.out.println(s);
        }
    }
}
