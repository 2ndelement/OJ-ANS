import java.util.*;

class Main {
    public int orderNumberCnt(int[] arr) {
        if (arr.length < 3) return 0;
        int cnt = 0;
        for (int i = 0; i < arr.length; i++)
            for (int j = i + 1; j < arr.length; j++)
                for (int k = j + 1; k < arr.length; k++) {
                    int diff1 = arr[j] - arr[i];
                    int diff2 = arr[k] - arr[j];
                    if (diff1 * diff2 > 0) cnt++;
                }
        return cnt;
    }


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Main m = new Main();
        System.out.println(m.orderNumberCnt(arr));
    }
}