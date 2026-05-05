public class BestTimeToBuyAndSellStock {

    private static int maxProfits(int[] prices) {
        int[][] dp = new int[prices.length][2];

        dp[0][0] = prices[0];
        dp[0][1] = 0;

        for(int i=1;i<prices.length;i++) {
            // tracks min_prices till i
            dp[i][0] = Math.min(dp[i-1][0], prices[i]);
            // tracks max profits till i
            dp[i][1] = Math.max(dp[i-1][1], prices[i] - dp[i][0]);
        }

        return dp[prices.length-1][1];
    }

    public static void main(String[] args) {
        int maxProfit = maxProfits(new int[]{10,8,7,5,2});
        System.out.println(maxProfit);
    }
}
