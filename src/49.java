import java.util.Scanner;

class Main {
    public static int MOD = 1000000007;

    public static long numWays(int n, int k) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return k;
        }
        long[] dp = new long[n];
        dp[0] = k;
        dp[1] = (long) k * k;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] * (k - 1) % MOD + dp[i - 2] * (k - 1) % MOD;
        }
        return dp[n - 1] % MOD;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        System.out.println(numWays(n, k));
    }
}