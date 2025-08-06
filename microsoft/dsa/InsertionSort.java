public class InsertionSort {
    void sort(int arr[]) {
        for(int i=1;i<arr.length;i++) {
            int current = arr[i];
            int j = i-1;
            while(j>=0 && arr[j] > current) {
                arr[j+1] = arr[j];
                j--;
            } 
            arr[j+1] = current;
        }
    }

    public static void main(String[] args) {
        InsertionSort insertionSort = new InsertionSort();
        int[] array = new int[]{3,2,1,5,6};
        insertionSort.sort(array);
        for (Integer i : array) {
            System.out.println(i);
        }
    }
}
