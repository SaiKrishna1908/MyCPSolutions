public class SearchInSortedRotatedArray {
    public static int search(int[] nums, int target) {
        int low = 0;
        int high = nums.length-1;

        while (low < high) {
            int mid = low + (high - low)/2;

            if (nums[mid] < nums[high]) {
                high  = mid;
            } else {
                low = mid + 1;
            }
        }

        int pivot = low;
        low = 0;
        high = nums.length -1;

        if (pivot != 0 && target >= nums[0]) {
            high = pivot - 1;
        } else {
            low = pivot;
        }

        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] > target) {
                high = mid -1 ;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        System.out.println(SearchInSortedRotatedArray.search(new int[]{1}, 1));
    }
}
