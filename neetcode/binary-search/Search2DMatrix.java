import java.util.Arrays;

class Search2DMatrix {

    private static boolean searchMatrix(int[][] matrix, int target) {

        int[] rows = new int[matrix.length];

        for(int i=0;i<matrix.length;i++) {
            rows[i] = matrix[i][0];
        }

        int low = 0;
        int high = rows.length;
        int row = 0;

        // binary search on rows
        while(low < high) {
            row = low + (high - low) / 2;

            if (target < rows[row]) {
                high = row;
            } else if (target > rows[row]) {
                low = row+1;
            } else {
                return true;
            }
        }

        if (rows[row] > target && row != 0) {
            row--;
        }

        int[] columns = new int[matrix[row].length];

        for(int i=0;i<columns.length;i++) {
            columns[i] = matrix[row][i];
        }

        System.out.println(Arrays.toString(columns));

        System.out.println(row);

        low = 0;
        high = columns.length;
        int col = 0;
        while (low < high) {
            col = low + (high - low)/2;

            if (target < columns[col] ) {
                high = col;
            } else if (target > columns[col]) {
                low = col+1;
            } else {
                return true;
            }
        }
    
        System.out.println(col);
        return false;
    }
    public static void main(String[] args) {
        int matrix[][] = new int[][]{
            {1,2,4,8},
            {10,11,12,13},
            {14,20,30,40}
        };
        System.out.println(Search2DMatrix.searchMatrix(matrix, 13));
    }
}