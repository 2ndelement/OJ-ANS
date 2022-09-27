import java.util.Scanner;

class Main {
    public static int longestSubsequence(int[] arr, int difference) {
        int longestLength = 0;
        int[] dp = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] - arr[j] == difference) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            longestLength = Math.max(longestLength, dp[i]);
        }
        return longestLength;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int difference = scanner.nextInt();
        System.out.println(longestSubsequence(arr, difference));
    }
}