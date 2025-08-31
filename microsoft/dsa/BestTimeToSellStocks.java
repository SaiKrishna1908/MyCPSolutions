public class BestTimeToSellStocks {
    int maxProfit(int[] prices) {
	    int currentMin = prices[0];
		int globalMin = 0;
		
		for(int i=1;i<prices.length;i++) {
			if (prices[i] < currentMin) {
				currentMin = prices[i];
			}
			
			globalMin = Math.max(globalMin, prices[i] - currentMin);
		}
		
		return globalMin;
	}
    
    public static void main(String[] args) {
        BestTimeToSellStocks s = new BestTimeToSellStocks();
        test(s, new int[]{7, 1, 5, 3, 6, 4}, 5);   // buy 1, sell 6
        test(s, new int[]{7, 6, 4, 3, 1}, 0);      // no profit
        test(s, new int[]{1, 2, 3, 4, 5}, 4);      // buy 1, sell 5
        test(s, new int[]{2, 4, 1}, 2);            // buy 2, sell 4
        test(s, new int[]{3, 3, 3}, 0);            // flat prices
        test(s, new int[]{2}, 0);                  // single day
    }

    private static void test(BestTimeToSellStocks s, int[] prices, int expected) {
        int actual = s.maxProfit(prices);
        System.out.println(java.util.Arrays.toString(prices)
            + " -> profit=" + actual + " (expected " + expected + ") "
            + (actual == expected ? "OK" : "FAIL"));
    }
}
