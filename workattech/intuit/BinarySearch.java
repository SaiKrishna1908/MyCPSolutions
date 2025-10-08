public class BinarySearch {

    // [2,3,4,5,6,7]  
    // size = 6
    // mid = 5-0 + 5/2
    // mid = 0 + (5-0)/2 = 2

    static int search(int[] arr, int target) {
        int low = 0;
        int high = arr.length;

        while(low < high) {
            int mid = low + (high - low)/2;
            if (arr[mid] < target) {
                low = mid + 1;
            } else if (arr[mid] > target) {
                high = mid;
            } else {
                return mid;
            }
        }

        return -1;
    }

    public static void main(String[] args) {        
        System.out.println(search(new int[]{1,2,3,4,5,6}, 1) );
        System.out.println(search(new int[]{1,2,3,4,5,6}, 2) );
        System.out.println(search(new int[]{1,2,3,4,5,6}, 3) );
        System.out.println(search(new int[]{1,2,3,4,5,6}, 4) );
        System.out.println(search(new int[]{1,2,3,4,5,6}, 5) );
        System.out.println(search(new int[]{1,2,3,4,5,6}, 6) );
    }
}
