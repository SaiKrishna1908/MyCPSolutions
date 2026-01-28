import java.util.Arrays;

class BinarySearch {
    public static int search(int[] nums, int target) {
        int low = 0;
        int high = nums.length;

        while(low < high) {
            int mid = low + (high - low)/2;
            if(target < nums[mid]) {
                high = mid;
            } else if (target > nums[mid]) {
                low = mid+1;
            } else {
                return mid;
            }
        }

        return -1;
    }
    
    public static void main(String[] args) {
        int pos = BinarySearch.search(new int[]{-1,0,2,4,6,8}, 4);
        System.out.println(pos);
    }
}