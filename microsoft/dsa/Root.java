

public class Root {
    int searchRoot (int num) {
		if (num == 0) {
			return 0;
		} else if (num == 1) {
			return 1;
		}
		int start = 0;
		int end = num;
		
		int result = 0;
		
		while (start <= end) {
			int mid = start + (end - start)/2;
			
			long midSquared = (long) mid * mid;
			
			if (midSquared == num) {
				return mid;
			} else if (midSquared < num) {
				result = mid;
				start = mid + 1;
			} else {
				end = mid-1;
			}
		}
		
		return result;
	}
    public static void main(String[] args) {
        Root root = new Root();
        int result = root.searchRoot(16);
        System.out.println(result);;
    }
}
