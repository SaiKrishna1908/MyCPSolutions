public class KokoEatingBanana {

    public static int minEatingSpeed(int[] piles, int h) {

       if (piles.length > h) {
         return -1;
       }

       int max = 0;

       for(int i=0;i<piles.length;i++) {
          max = Math.max(piles[i], max);
       }

       long low = 1;
       long high = max+1;
       long mid = 0;

       while(low != high) {

          mid = low + (high - low)/2l;

          if (canEat(mid, piles, h)) {            
            high = mid;
          } else {            
            low = mid + 1;
          }
       }
 
       return (int) low;
    }

    private static boolean canEat(long k, int[] piles, int h) {
        int sum = 0;

        for(int i=0;i<piles.length;i++) {
            sum += Math.ceil(((double)piles[i]/k));
        }

        return sum <= h;
    }

    public static void main(String[] args) {
        int result = KokoEatingBanana.minEatingSpeed(new int[]{25,10,23,4}, 4);
        System.out.println(result);
        int result2 = KokoEatingBanana.minEatingSpeed(new int[]{1,4,3,2}, 9);
        System.out.println(result2);
        int result3 = KokoEatingBanana.minEatingSpeed(new int[]{3,6,7,11}, 8);
        System.out.println(result3);
    }
}