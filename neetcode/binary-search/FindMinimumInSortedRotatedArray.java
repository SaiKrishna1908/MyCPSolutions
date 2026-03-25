public class FindMinimumInSortedRotatedArray {
    public static int findMin(int []nums) {
        int low = 0;
        int high = nums.length-1;

        while(low < high) {
            int mid = low + (high - low)/2;

            if (nums[mid] < nums[high]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
    public static void main(String[] args) {
        System.out.println(findMin(new int[]{8,9,10,11,1,2,3,4,5,6,7}));
        System.out.println(findMin(new int[]{4,5,6,1,2,3,3}));
        System.out.println(findMin(new int[]{4,5,6,1,2,3}));
        System.out.println(findMin(new int[]{1,2,3}));
    }
}
