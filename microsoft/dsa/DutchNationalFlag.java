public class DutchNationalFlag {
    void sortTheArray (int[] A) {
	    int[] bucket = new int[3];
		for(int i=0;i<A.length;i++) {
			bucket[A[i]]++;
		}
		
		int i = 0;
		for(int j=0;j<3;j++) {
			while(bucket[j]-->0) {
				A[i] = j;
				i++;
			}
		}
	}

    public static void main(String[] args) {
        DutchNationalFlag dutchNationalFlag = new DutchNationalFlag();
        int array[] = new int[] {1,1,1,2,2,2,0,0,0};
        dutchNationalFlag.sortTheArray(array);

        for(int i=0;i<array.length;i++) {
            System.out.println(array[i]);
        }
    }
}
