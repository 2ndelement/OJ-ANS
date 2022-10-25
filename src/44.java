import java.util.Scanner;

class Main {
    public static int maxProfit(int[] prices) {
        int[] profits = new int[prices.length];
        for (int i = 1; i < prices.length; i++) {
            profits[i] = prices[i] - prices[i - 1];
        }
        int[][] dp = new int[prices.length + 1][2];
        for (int i = 1; i < prices.length; i++) {
            dp[i][0] = Math.max(profits[i], dp[i - 1][0] + profits[i]);
        }
        for (int i = 1; i < prices.length; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], dp[i][0]);
        }
        for (int i = prices.length - 1; i >= 0; i--) {
            dp[i][1] = Math.max(profits[i], dp[i + 1][1] + profits[i]);
        }
        for (int i = prices.length - 1; i >= 0; i--) {
            dp[i][1] = Math.max(dp[i][1], dp[i + 1][1]);
        }
        int res = 0;
        for (int i = 0; i < prices.length; i++) {
            res = Math.max(res, dp[i][0] + dp[i + 1][1]);
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] prices = new int[n];
        for (int i = 0; i < n; i++) {
            prices[i] = scanner.nextInt();
        }
        System.out.println(maxProfit(prices));
    }
}