import java.util.Scanner;

class Main {
    public static int minCost(int[][] cost) {
        int n = cost.length;
        int m = cost[0].length;
        int[][] dp = new int[n][m];
        dp[0][0] = cost[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + cost[i][0];
        }
        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j - 1] + cost[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + cost[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] cost = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = sc.nextInt();
            }
        }
        System.out.println(minCost(cost));
    }
}