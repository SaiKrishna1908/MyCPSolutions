public class CompareVersion {
    static String stripLeadingZeros(String s) {
		int i =0;
		while(s.charAt(i) == '0') {
			i++;			
		}
		
		return s.substring(i,s.length());
	}
    static int compareVersion(String version1, String version2) {
		String[] v1 = version1.split("\\.");
		String[] v2 = version2.split("\\.");
		
		boolean append1 = v1.length > v2.length;
		int n = v1.length;
		int m = v2.length;
		
		if (append1) {
			for(int i=0;i<n-m;i++) {
				version2 += ".0";
			} 
		} else {
			for(int i=0;i<m-n;i++) {
				version1+=".0";
			}
		}
		
		System.out.println(version1);
		System.out.println(version2);
		
		v1 = version1.split("\\.");
		v2 = version2.split("\\.");
		
		String s1 = "";
		String s2 = "";
		
		for(int i=0;i<v1.length;i++) {
			s1 += Integer.parseInt(v1[i]);
			s2 += Integer.parseInt(v2[i]);
		}		
		
        if (s1.equals(s2)) {
            return 0;
        }


        return s1.compareTo(s2);
	}
    public static void main(String[] args) {
        // compareVersion("2.3.0", "2.3");
        System.out.println(stripLeadingZeros("00000"));
    }
}
