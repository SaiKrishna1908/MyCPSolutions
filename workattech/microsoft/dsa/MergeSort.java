public class MergeSort {    
    public void merge(int array[], int left, int mid, int right) {

        int leftSize = mid-left+1;
        int rightSize = right-mid;

        int[] leftArray = new int[leftSize];
        int[] rightArray = new int[rightSize];

        for(int i=0;i<leftArray.length;i++) {
            leftArray[i] = array[left+i];
        }

        for(int i=0;i<rightArray.length;i++) {
            rightArray[i] = array[mid+1+i];
        }


        int i = 0, j = 0;
        int k =left;

        while(i<leftSize && j < rightSize) {
            if (leftArray[i] < rightArray[j]) {
                array[k] = leftArray[i];
                i++;
            } else {
                array[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < leftSize) {
            array[k] = leftArray[i];
            k++;
            i++;
        }

        while(j < rightSize) {
            array[k] = rightArray[j];
            k++;
            j++;
        }
    }

    public void mergeSort(int array[], int left, int right) {
        int mid = left + (right - left)/2;

        if (left >= right) {
            return;
        }

        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);
        merge(array, left, mid, right);
    }

    public static void main(String[] args) {

        int array[] = new int[]{3,5,1,2,6,8};
        MergeSort mergeSort = new MergeSort();
        mergeSort.mergeSort(array, 0, array.length-1);

        for(int i=0;i<array.length;i++) {
            System.out.println(array[i]);
        }
    }   
}
