import java.util.Scanner;

class Main {
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int maxProduct(int[] nums) {
        int[][] dp = new int[nums.length][2];
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < 0) {
                swap(dp[i - 1], 0, 1);
            }
            int a = dp[i - 1][0] * nums[i];
            int b = dp[i - 1][1] * nums[i];
            dp[i][0] = Math.max(nums[i], a);
            dp[i][1] = Math.min(nums[i], b);
            max = Math.max(max, dp[i][0]);
        }
        return max;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(maxProduct(nums));
    }
}