// [7,8,9,10,1,2,3,4]
// low = 0, high = 5
// mid = 0 + 5/2 = 2
// 
public class SearchRotatedSortedArray {
    static int getPivot(int[] arr, int low , int high) {
        while(low < high) {
            if (arr[low] < arr[high]) {
                return low;
            }

            int mid = low + (high - low)/2;

            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
    static int getElementIndex(int[] array, int target) {        
        int pivot = getPivot(array, 0, array.length-1);

        if (array[pivot] == target) {
            return pivot;
        }
        
        int low = target >= array[0]  ? 0 : pivot;
        int high = target >= array[0] ? pivot : array.length;
                
        while (low < high) {
            int mid = low + (high - low)/2;

            if (array[mid] > target) {
                high = mid;
            } else if (array[mid] < target) {
                low = mid + 1;
            } else {
                return mid;
            }
        }

        return -1;
    } 
    public static void main(String[] args) {
        System.out.println(getElementIndex(new int[]{4,5,6,7,0,1,2}, 4));                
    }
}
