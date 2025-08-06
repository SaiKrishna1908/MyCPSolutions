public class LargestContiguousSum {
    public int findLargestContiguousSum(int[] array) {
        int currentSum = array[0];
        int maxSum = array[0];

        for(int i=1;i<array.length;i++) {
            currentSum = Math.max(currentSum + array[i], array[i]);
            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }
    public static void main(String[] args) {
        int array[] = new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4};
        LargestContiguousSum largestContiguousSum = new LargestContiguousSum();
        int result = largestContiguousSum.findLargestContiguousSum(array);
        System.out.println(result);
    }
}
