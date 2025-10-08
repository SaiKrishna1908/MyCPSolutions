import java.util.ArrayDeque;
import java.util.Queue;

public class NumberOfIslands {

    private static boolean isValid(int i, int j, int n, int m) {
        return (i < n && i >= 0 && j >=0 && j<m);
    }

    private static void traverse(boolean[][] visited, int[][] island, int i, int j) {
        if (!isValid(i, j, island.length, island[0].length) || visited[i][j] || island[i][j] == 0) {
            return;
        }

        visited[i][j] = true;
        int[][] directions = new int[][]{{1,0}, {0,1}, {-1,0},{0, -1}};

        for(int idx=0;idx<directions.length;idx++) {
            int newX = i + directions[idx][0];
            int newY = j + directions[idx][1];
            traverse(visited, island, newX, newY);    
        }
    }

    private static int getNumberOfIslands(int[][] island) {        

        int count = 0;

        boolean[][] visited = new boolean[island.length][island[0].length];

        for(int i=0;i<island.length;i++) {
            for(int j=0;j<island[0].length;j++) {
                if (island[i][j] == 1 && !visited[i][j]) {
                    count++;
                    traverse(visited, island, i, j);            
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        System.out.println(getNumberOfIslands(new int[][]{{1,1,0,1}, {1,0,1,1}, {0,1,0,1}}));
    }    
}
