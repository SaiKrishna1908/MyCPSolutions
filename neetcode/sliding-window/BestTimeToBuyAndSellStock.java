public class BestTimeToBuyAndSellStock {
    
    /**
     * This is the sliding window approach.
     * The window grows as long as prices[l] < prices[r], because there is a possiblity that we might encounter new r
     * which maximises (prices[r]-prices[l])
     * 
     * If prices[l] > prices[r], we know 
     * @param prices
     * @return
     */
    private static int maxProfits(int[] prices) {
        int l=0,r=1;

        int max_profits = 0;

        while (r < prices.length) {
            if (prices[l] < prices[r]) {
                max_profits = Math.max(max_profits, prices[r] - prices[l]);
            } else {
                l = r;
            }

            r+=1;
        }

        return max_profits;
    }
    public static void main(String[] args) {
         int maxProfit = maxProfits(new int[]{10,1,5,6,7,1});
        System.out.println(maxProfit);
    }
}