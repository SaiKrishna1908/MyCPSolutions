import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class ValidSudoku {
  public static boolean isValidSudoku(char[][] board) {

    // check row duplicates
    for (int i = 0; i < board.length; i++) {
      int[] bucket = new int[10];
      for (int j = 0; j < board[i].length; j++) {
        if (board[i][j] != '.') {
          int number = (int) board[i][j] - '0';
          if (bucket[number] > 0) {
            return false;
          }
          bucket[number]++;
        }
      }
    }

    // check column duplicates
    for (int j = 0; j < board.length; j++) {
      int[] bucket = new int[10];
      for (int i = 0; i < board[j].length; i++) {
        if (board[i][j] != '.') {
          int number = (int) board[i][j] - '0';
          if (bucket[number] > 0) {
            return false;
          }
          bucket[number]++;
        }
      }
    }

    // check 3x3 duplicates
    /*
     * n=0,3
     * m=0,3
     */

    int[] row = new int[] { 0, 3, 6 };
    int[] col = new int[] { 0, 3, 6 };
    for (int i = 0; i < 3; i++) {
      for (int z = 0; z < 3; z++) {
        int lowr = row[i];
        int lowc = col[z];
        Map<Character, Integer> subMap = new HashMap<>();
        for (int j = lowr; j < lowr + 3; j++) {
          for (int k = lowc; k < lowc + 3; k++) {
            if (board[j][k] != '.') {
              if (subMap.containsKey(board[j][k])) {
                return false;
              } else {
                subMap.put(board[j][k], 1);
              }
            }

          }
        }
      }
    }

    return true;
  }

  public static void main(String[] args) {
    System.out.println(isValidSudoku(new char[][] { 
      { '.', '.', '4', '.', '.', '.', '6', '3', '.' },
      { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
      { '5', '.', '.', '.', '.', '.', '.', '9', '.' },
      { '.', '.', '.', '5', '6', '.', '.', '.', '.' },
      { '4', '.', '3', '.', '.', '.', '.', '.', '1' },
      { '.', '.', '.', '7', '.', '.', '.', '.', '.' },
      { '.', '.', '.', '5', '.', '.', '.', '.', '.' },
      { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
      { '.', '.', '.', '.', '.', '.', '.', '.', '.' } }));
  }
}
